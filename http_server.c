//
// Created by Shifeng,Zhang on 2018/10/31.
//

#include "http_server.h"
#include "log.h"
#include "ioloop.h"
#include "connection.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/signal.h>
#include <arpa/inet.h>  // 网络地址
#include <sys/epoll.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CONNECTIONS 1024000
#define MAX_BACKLOG 128

static int _server_init(server_t *server);
static void _server_connection_handler(ioloop_t *loop, int listen_fd, unsigned int events, void *args);

server_t* server_create()
{
    // 服务器
    server_t * server;
    // io事件循环
    ioloop_t *ioloop;

    server = (server_t *)calloc(1, sizeof(server_t));
    if (server == NULL) {
        error("create server error");
        return NULL;
    }

    ioloop = ioloop_create(MAX_CONNECTIONS);
    if (ioloop == NULL) {
        error("create ioloop error");
        return NULL;
    }

    server->addr     = "127.0.0.1";
    server->port     = 8000;
    server->ioloop   = ioloop; // 
    server->state    = SERVER_INIT;  // 服务器初始化
    server->loglevel = INFO;

    return server;

}

int server_start(server_t *server)
{
    // 设置服务器启动后的日志级别
    configure_log(server->loglevel, server->logfile, !server->daemonize);

    if (_server_init(server) < 0) {
        error("Error initializing server");
        return -1;
    }

    // 忽视管道信号
    if (signal(SIGPIPE, SIG_IGN) == SIG_ERR) {
        error("Error blocking SIGPIPE");
    }

    info("Start running server on %d", server->port);
    server->state = SERVER_RUNNING;
    return ioloop_start(server->ioloop);
}

/*
服务器初始化
*/
static int _server_init(server_t *server)
{
    int listen_fd; // 监听的句柄
    struct sockaddr_in addr; // 地址

    // 创建和绑定套接字
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        error("Error creating socket");
        return -1;
    }

    bzero(&addr, sizeof(struct sockaddr_in));
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(server->port);

    if (bind(listen_fd, 
        (struct sockaddr *) &addr, sizeof(struct sockaddr_in)) == -1) {
        error("Error binding adress");
        close(listen_fd);
        return -1;
    }

    // 监听套接字
    if (listen(listen_fd, MAX_BACKLOG) == -1) {
        error("Error listening");
        close(listen_fd);
        return -1;
    }

    // 设置非阻塞
    if (set_nonblocking(listen_fd) < 0) {
        error("Error configure non-blocking");
        close(listen_fd);
        return -1;
    }
    server->listen_fd = listen_fd;

    if (ioloop_add_handler(server->ioloop, 
                            listen_fd, 
                            EPOLLIN,
                            _server_connection_handler, 
                            server) < 0) {
        error("Error add connection handler");
        return -1;
    }
    return 0;
}

static void _server_connection_handler(ioloop_t *loop, int listen_fd, unsigned int events, void *args)
{
    connection_t *conn;
    server_t *server = (server_t*)args;
    while ((conn = connection_accept(server, listen_fd)) != NULL) {
        connection_run(conn);
    }
}