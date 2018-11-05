#ifndef KIME_SITE_H
#define KIME_SITE_H

#include "http.h"
#include "dict.h"
#include <regex.h>

#define MAX_HOST_LENGTH 64
#define MAX_SITES 100

typedef struct _location location_t;
typedef struct _site     site_t;

struct _location {
    union {
        char *prefix;
        regex_t *regex;
    } uri;
    int match_type;
    handler_func handler; // 请求处理函数
    void *handler_conf;
    struct _location *next;
};

/*
 使用一个单链表维护全部的location,正则表达式具有更高的优先级
 正则之后是一个正常的匹配，我们遵循从最长到最短的原则

 保证尽可能最好的匹配
*/
struct _site {
    char host[MAX_HOST_LENGTH];
    location_t *location_head; 
};

typedef struct _site_conf {
    site_t *sites[MAX_SITES];
    int site_size;
    dict *size_hash;
} site_conf_t;

#endif