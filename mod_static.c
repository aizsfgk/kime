//
// Created by Shifeng,Zhang on 2018/10/26.
//

#include <unistd.h>
#include <sys/types.h>
#include "mod_static.h"
#include "dict.h"
#include "log.h"

#define FILE_TYPE_COUNT 10

/*
 mime_type
 */
typedef struct _mime_type {
    char *content_type; // 内容类型
    char *exts[FILE_TYPE_COUNT];  // 文件类型
} mime_type_t;

mime_type_t standard_types[] = {
    {"text/html",                {"html", "htm", "shtml", NULL}},
    {"text/css",                 {"css", NULL}},
    {"text/xml",                 {"xml", NULL}},
    {"text/plain",               {"txt", NULL}},
    {"image/png",                {"png", NULL}},
    {"image/gif",                {"gif", NULL}},
    {"image/tiff",               {"tif", "tiff", NULL}},
    {"image/jpeg",               {"jpg", "jpeg", NULL}},
    {"image/x-ms-bmp",           {"bmp", NULL}},
    {"image/svg+xml",            {"svg", "svgz", NULL}},
    {"application/x-javascript", {"js", NULL}}
};

int mod_static_init()
{
    int i,j;
    size_t size;

    char **ext = NULL;

    size = sizeof(standard_types) / sizeof(standard_types[0]);

    dict *md = dictCreate((int)size * 2);
    if (md == NULL) {
        error("create mime type hash error");
        return -1;
    }

    for (i=0; i<size; i++) {
        for (ext = standard_types[i].exts, j=0;
                *ext != NULL && j<FILE_TYPE_COUNT; ext++, j++) {

            int res = dictAdd(md, *ext, standard_types[i].content_type);
            if (res != 0) {
                error("add dict error key: %s, val %s\n", *ext, standard_types[i].content_type);
            }
        }
    }

    dictDisplay(md);
    return 0;
}

int static_file_handle(request_t *req, response_t *resp, handler_ctx_t *ctx)
{
    return 0;
}