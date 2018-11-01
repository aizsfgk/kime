#include "option.h"
#include "http.h"
#include "mod_static.h"
#include "dict.h"

#include <stdio.h>


int main(int argc, char *argv[])
{
    opt_t * option;
    server_t *server;

    /*
     * 解析命令行
     */
    option = init_opts(argc, argv);

    /*
     * 创建服务器
     */
    if (option->root_dir != NULL) {
        server = create_simple_server(option);
    } else {
        server = create_server(option);
    }

    if (server == NULL) {
        error("kime create server error");
        return 1;
    }

    if (option->is_conf_test) {
        print_conf_detail(server);
        return 0;
    }

    /*
     * 启动服务器
     */


    /*
     * 销毁服务器
     */
    
    free(option);
    return 0;
}

static void print_conf_detail(server_t *server)
{
    int i;
    site_t *site;
    location_t *loc;
    site_conf_t *site_conf = (site_conf_t *) server->handler_conf;
}