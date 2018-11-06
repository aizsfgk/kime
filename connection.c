#include "connection.h"
#include "http.h"
#include "log.h"
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <netinet/in.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void _set_tcp_nodelay(int fd);

connection_t *connection_accept(server_t *server, int listen_fd)
{
    connection_t *conn;
    socklen_t addr_len;
    int conn_fd;
    struct sockaddr_in remote_addr;

    // 将监听套接字转换为已连接套接字
    addr_len = sizeof(struct sockaddr_in);
    conn_fd = accept(listen_fd, (struct sockaddr*)&remote_addr, &addr_len);
    if (conn_fd == -1) {
        if (errno != EAGAIN && errno != EWOULDBLOCK) {
            error("Error accept new connection");
        }
        return NULL;
    }

    conn = (connection_t *)calloc(1, sizeof(connection_t));
    if (conn == NULL) {
        goto error;
    }

    bzero(conn, sizeof(connection_t));
    // 设置非阻塞
    if (set_nonblocking(conn_fd) < 0) {
        error("Error set conn_fd no-blocking");
        goto error;
    }

    // tcp nodelay
    // 客户端关闭Nagle算法
    _set_tcp_nodelay(conn_fd);

    conn->server = server;
    inet_ntop(AF_INET, &remote_addr.sin_addr, conn->remote_ip, 20);
    conn->remote_port = remote_addr.sin_port;
    conn->state = CONN_ACTIVE;
    conn->request = request_create(conn);
    conn->response = request_create(conn);
    conn->context = context_create();
    return conn;

error:
    close(conn_fd);
    if (conn != NULL) {
        free(conn);
    }
    return NULL;
}

int connection_run(connection_t *conn)
{
    return 0;
}

static void _set_tcp_nodelay(int fd)
{
    int enable = 1;
    setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, (void *)&enable, sizeof(enable));
}