//
// Created by Shifeng,Zhang on 2018/11/06
//

#ifndef KIME_CONNECTION_H
#define KIME_CONNECTION_H

#include "http.h"

typedef struct _connection connection_t;

typedef enum _connection_state {
    CONN_ACTIVE,
    CONN_CLOSING,
    CONN_CLOSED
} conn_stat_e;


struct _connection {
    server_t *server;
    char remote_ip[20];
    unsigned short remote_port;
    conn_stat_e state;
    request_t *request; 
    response_t *response;
    handler_ctx_t *context;
};


connection_t *connection_accept(server_t *server, int listen_fd);
int connection_run(connection_t *conn);

#endif