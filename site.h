#ifndef KIME_SITE_H
#define KIME_SITE_H

#include "http.h"
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
*/
struct _site {
    char host[MAX_HOST_LENGTH];
    location_t *location_head; 
};

#endif