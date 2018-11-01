//
// Created by Shifeng,Zhang on 2018/10/31.
//

#include "ioloop.h"
#include "log.h"
#include <stdio.h>
#include <sys/epoll.h>
#include <stdlib.h>

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