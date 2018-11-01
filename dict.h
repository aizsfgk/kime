//
// Created by Shifeng,Zhang on 2018/10/26.
//

#ifndef KIME_DICT_H
#define KIME_DICT_H

#include <stdlib.h>

#define DICT_OK 0
#define DICT_ERR 1
#define DICT_HT_INITIAL_SIZE 8

typedef struct _dictEntry {
    void *key;
    void *val;
    struct _dictEntry *next;
} dictEntry;

typedef struct _HashTable {
    dictEntry **table;
    int size;      // 总共的空间大小
} HashTable;

typedef HashTable dict;


// 创建
dict *dictCreate(int size);
// 添加
int dictAdd(dict *d, void *key, void *val);
// 查询
void *dictGet(dict *d, void *key);
// 跟新
int dictUpdate(dict *d, void *key, void *val);
// 删除
int dictDel(dict *d, void *key);
// 显示
int dictDisplay(dict *d);
// 清除
int dictClean(dict *d);


#endif //KIME_DICT_H
