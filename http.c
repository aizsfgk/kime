//
// Created by Shifeng,Zhang on 2018/10/26.
//

#include "http.h"
#include "log.h"
#include "mod_static.h"
#include "http_server.h"
#include <stdlib.h>
#include <string.h>

mod_static_conf_t conf;

server_t *create_simple_server(opt_t *option)
{
    bzero(&conf, sizeof(mod_static_conf_t));

    // 模块初始化
    if (mod_static_init() < 0) {
        error("Error initializing mod_static\n");
        return NULL;
    }

    /*
     * 将option的配置赋值给服务器
     */
    server_t *server = (server_t *) calloc(1, sizeof(server_t));
    if (server == NULL)
    {
        error("server calloc error");
        return NULL;
    }

    server = server_create();
    if (server == NULL) {
        error("server_create error");
        return NULL;
    }

    conf.root = option->root_dir;
    conf.expire_hours = 24;
    conf.enable_list_dir = 1;
    conf.index = "index.html";
    if (option->port > 0) {
        server->port = option->port;
    }
    server->handler = static_file_handle;
    server->handler_conf = &conf;

    return server;
}


server_t *create_server(opt_t *option)
{
    server_t *server = (server_t *) calloc(1, sizeof(server_t *));
    if (server == NULL)
    {
        error("server calloc error");
        return NULL;
    }

    return server;
}