//
// Created by Shifeng,Zhang on 2018/10/31.
//

#include "http_server.h"
#include "log.h"
#include "ioloop.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <arpa/inet.h>  // 网络地址

#define MAX_CONNECTIONS 1024000

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
    server->state    = SERVER_INIT;  // 服务器厨初始化
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

} 