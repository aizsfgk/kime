//
// Created by Shifeng,Zhang on 2018/10/26.
//

#ifndef KIME_HTTP_H
#define KIME_HTTP_H

#include "option.h"
#include "ioloop.h"

// 请求结构体
typedef struct _request         request_t;
// 响应结构体
typedef struct _response        response_t;
// 上下文处理句柄体
typedef struct _handler_ctx     handler_ctx_t;

typedef struct _server server_t;

typedef int (*handler_func)(request_t *request, response_t *response, handler_ctx_t *ctx);

typedef enum _server_state {
    SERVER_INIT = 0,   // 初始化
    SERVER_RUNNING,    // 运行中
    SERVER_STOPPED     // 已停止
} server_state;

struct _server {
    char *conf_file;     // 配置文件
    int is_conf_test;    // 是否打印测试
    int is_simple_mode;  // 是否简单模式
    char *root_dir;      // 根目录

    char *addr;          // 地址
    unsigned int port;   // 端口
    ioloop_t *ioloop;    // 事件循环
    server_state state;  // 服务器状态
    int loglevel;        // 日志级别
    char *logfile;      // 日志文件
    int daemonize;       // 是否事精灵进程
    int listen_fd;

    handler_func handler;// 句柄函数
    void *handler_conf;  // 配置

};


server_t* create_simple_server(opt_t *);
server_t* create_server(opt_t *);

request_t *request_create(conn);
response_t *response_create(conn);
handler_ctx_t *context_create();



#endif //KIME_HTTP_H
