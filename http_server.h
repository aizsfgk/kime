//
// Created by Shifeng,Zhang on 2018/10/31.
//

#ifndef KIME_HTTP_SERVER_H
#define KIME_HTTP_SERVER_H

#include "http.h"

server_t* server_create();
int server_start(server_t *server);
int server_destroy(server_t *server);

#endif //KIME_HTTP_SERVER_H
