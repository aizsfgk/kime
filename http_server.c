//
// Created by Shifeng,Zhang on 2018/10/31.
//

#include "http_server.h"
#include "log.h"
#include "ioloop.h"
#include <stdio.h>
#include <stdlib.h>

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