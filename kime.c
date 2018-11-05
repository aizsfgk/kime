#include "option.h"
#include "http.h"
#include "log.h"
#include "http_server.h"
#include "mod_static.h"
#include "dict.h"
#include "site.h"

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

    /*
    // 只有有配置文件后，才能使用这个选项
    if (option->is_conf_test) {
        print_conf_detail(server);
        return 0;
    }
    */

    /*
     * 启动服务器
     */
    server_start(server);


    /*
     * 销毁服务器
     */
    
    free(option);
    return 0;
}