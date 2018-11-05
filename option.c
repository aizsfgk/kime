//
// Created by Shifeng,Zhang on 2018/10/25.
//

#include "option.h"
#include "log.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

extern char *optarg;

#define DEFAULT_CONF "./server.conf"

opt_t *init_opts(int argc, char *argv[])
{
    opt_t  *opt = NULL;
    int opt_id;

    opt = (opt_t*) calloc(1, sizeof(opt_t));
    if (opt == NULL) {
        error("Error allocating memory\n");
        return NULL;
    }
    opt->conf_file = DEFAULT_CONF;

    /*
        getopt系统调用

        -r 和 -t 不能同时
     */
    while ((opt_id = getopt(argc, argv, "c:p:r:t")) != -1) {
        switch(opt_id) {
            case 'c':
                opt->conf_file = optarg;  // 获取服务器配置
                break;
            case 'p':
                opt->port = atoi(optarg); // 获取端口
                break;

            case 't':
                opt->is_conf_test = 1;    // -t 则进行服务器测试
                break;

            case 'r':
                opt->root_dir = optarg;
                break;

            default:
                fprintf(stderr, "Usage: %s [-c configfile] [-t]\n", argv[0]);
                fprintf(stderr, "       %s [-r rootdir] [-p port]\n", argv[0]);
                free(opt);
                return NULL;
        }
    }
    return opt;
}
