//
// Created by Shifeng,Zhang on 2018/10/26.
//

#ifndef KIME_MOD_STATIC_H
#define KIME_MOD_STATIC_H

#include "http.h"

// 模块静态配置
typedef struct _mod_static_conf {

    // 根目录
    char *root;
    // 索引
    char *index;
    // 激活列表目录
    int  enable_list_dir;
    // 展示隐藏的文件
    int  show_hidden_file;
    // 激活etag
    int  enable_etag;
    // 激活range_req[范围请求]
    int  enable_range_req;

    // -1 means not set expires header; other means
    // the expiration time (in hours)
    int  expire_hours;
} mod_static_conf_t;

int mod_static_init();
int static_file_handle(request_t *req, response_t *resp, handler_ctx_t *ctx);

#endif //KIME_MOD_STATIC_H
