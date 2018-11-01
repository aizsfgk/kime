//
// Created by Shifeng,Zhang on 2018/10/25.
//

#ifndef KIME_OPTION_H
#define KIME_OPTION_H

typedef struct opt_s {
    char *conf_file;        // 配置文件
    int  is_simple_mode;    // 是否是简单模式
    char *root_dir;         // root目录
    int port;    // 端口
    int  is_conf_test;      // 是否配置测试
} opt_t;

opt_t *init_opts(int argc, char *argv[]);

#endif //KIME_OPTION_H
