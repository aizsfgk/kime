//
// Created by Shifeng,Zhang on 2018/10/31.
//

#include "ioloop.h"
#include "log.h"
#include <stdio.h>
#include <sys/epoll.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

ioloop_t    *ioloop_create(unsigned int maxfds)
{
    ioloop_t *loop = NULL;
    int epoll_fd;
    struct _io_callback *handlers = NULL;

    loop = (ioloop_t *)calloc(1, sizeof(ioloop_t));
    if (loop == NULL) {
        error("create loop error");
        return NULL;
    }

    handlers = (struct _io_callback *)calloc(maxfds, sizeof(struct _io_callback));
    if (handlers == NULL) {
        error("create handlers error");
        free(loop);
        return NULL;
    }

    epoll_fd = epoll_create(maxfds);
    if (epoll_fd < 0) {
        error("create epoll_fd error");
        free(loop);
        free(handlers);
        return NULL;
    }

    loop->handlers = handlers;
    loop->epoll_fd = epoll_fd;
    loop->callback_chain_idx = 0;
    loop->state = INITIALIZED;
    loop->callback_chains[0].callback_num = 0;
    loop->callback_chains[1].callback_num = 0;

    return loop;
}

int ioloop_add_handler(ioloop_t *loop, int fd, unsigned int events, io_handler handler, void *args)
{
    struct epoll_event ev;
    if (handler == NULL) {
        error("Error: handler is null");
        return -1;
    }
    ev.data.fd = fd;
    ev.events = events | EPOLLET; // ET 边缘出发，事件发生，只通知一次
    if (epoll_ctl(loop->epoll_fd, EPOLL_CTL_ADD, fd, &ev) == -1) {
        error("Error adding fd to epoll");
        return -1;
    }
    loop->handlers[fd].callback = handler;
    loop->handlers[fd].args = args;

    return 0;
}

#define MAX_EVENTS 1024
#define EPOLL_DEFAULT_TIMEOUT 100

int ioloop_start(ioloop_t *loop)
{
    struct epoll_event events[MAX_EVENTS];
    struct _callback_chain *current_chain;
    int epoll_fd, nfds, i, fd, epoll_timeout;
    io_handler handler;
    void *args;

    if (loop->state != INITIALIZED) {
        error("Error: count not restart an IO loop");
        return -1;
    }

    epoll_fd = loop->epoll_fd;
    loop->state = RUNNING;

    while (loop->state == RUNNING) {
        // 开始处理回调
        current_chain = loop->callback_chains + loop->callback_chain_idx;
        if (current_chain->callback_num > 0) {
            loop->callback_chain_idx = (loop->callback_chain_idx + 1) % 2;
            for (i=0; i<current_chain->callback_num; i++) {
                current_chain->callbacks[i].callback(loop, current_chain->callbacks[i].args);
            }
            current_chain->callback_num = 0;
        }

        // wait for events
        epoll_timeout = EPOLL_DEFAULT_TIMEOUT;
        if (loop->callback_chains[loop->callback_chain_idx].callback_num > 0) {
            epoll_timeout = 0;
        }
        /*
        返回已经就绪的句柄数
        */
        nfds = epoll_wait(epoll_fd, events, MAX_EVENTS, epoll_timeout);
        if (nfds == -1) {
            error("epoll_wait");
            continue;
        }

        // 处理事件
        for (i=0; i<nfds; i++) {
            fd = events[i].data.fd;
            handler = loop->handlers[fd].callback;
            args = loop->handlers[fd].args;
            if (handler == NULL) {
                continue;
            }
            handler(loop, fd, events[i].events, args);
        }
    }

    close(epoll_fd);
    return 0;
}



int set_nonblocking(int sockfd)
{
    int opts;
    opts = fcntl(sockfd, F_GETFL);
    if (opts < 0) {
        return -1;
    }

    opts |= O_NONBLOCK;
    if (fcntl(sockfd, F_SETFL, opts) < 0) {
        return -1;
    }
    return 0;
}