//
// Created by Shifeng,Zhang on 2018/10/31.
//

#ifndef KIME_IOLOOP_H
#define KIME_IOLOOP_H

typedef struct _ioloop ioloop_t;
/*
函数指针
*/
typedef void (*io_handler)(ioloop_t *loop, int fd, unsigned int events, void *args);
typedef void (*callback_handler)(ioloop_t *loop, void *args);

#define MAX_CALLBACKS 10000

struct _callback {
    callback_handler    callback;
    void          *args;
};

struct _io_callback {
    io_handler      callback;
    void      *args;
};

struct _callback_chain {
    struct _callback    callbacks[MAX_CALLBACKS];
    int                 callback_num;
};

struct _ioloop {
    int                     epoll_fd;           // epoll句柄
    int                     state;              // 状态
    struct _io_callback     *handlers;          // io回调句柄
    struct _callback_chain  callback_chains[2]; // 回调句柄链路
    int                     callback_chain_idx; // 回调句柄索引
};

enum IOLOOP_STATES {
    INITIALIZED = 0,    // 初始化
    RUNNING = 1,        // 运行中
    STOPPED = 2         // 停止
};


ioloop_t    *ioloop_create(unsigned int maxfds);


#endif //KIME_IOLOOP_H
