#include <stdio.h>
#include <string.h>

#include "murmurhash2.h"
#include "dict.h"
#include "log.h"

static uint32_t feed = 32;

static int hashIndex(char *str)
{

/*
    经典hash算法
    unsigned int h;
    unsigned char *p;
    for (h=0, p = (unsigned char *)str; *p; p++)
        h = 31 * h + *p;

    return h;
*/
    // murmurhash2
    return murmurHash2(str, strlen(str), feed);
}

#define IDX(dict, key) (hashIndex(key) & (dict->size - 1))
// #define IDX(dict, key) (hashIndex(key) % dict->size)  // 经典hash算法

dict *dictCreate(int size)
{
    if (size < DICT_HT_INITIAL_SIZE)
        size = DICT_HT_INITIAL_SIZE;

    dict *d = (dict *)malloc(sizeof(dict));
    memset(d, 0, sizeof(dict));

    d->table = (dictEntry **)malloc(sizeof(dictEntry) * size);
    memset(d->table, 0, sizeof(dictEntry) * size);

    d->size = size;
    return d;
}

int dictAdd(dict *d, void *key, void *val)
{
    int idx = IDX(d, key);
    dictEntry *header, *entry;
    header = entry = d->table[idx];
    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            entry->val = val;
            return DICT_OK;
        }
        entry = entry->next;
    }

    dictEntry *newEntry = (dictEntry *)malloc(sizeof(dictEntry));
    if (newEntry == NULL)
        return DICT_ERR;
    memset(newEntry, 0, sizeof(dictEntry));

    newEntry->key = strdup(key);
    newEntry->val = val;
    newEntry->next = header;
    d->table[idx] = newEntry;

    return DICT_OK;
}

void *dictGet(dict *d, void *key)
{
    int idx = IDX(d, key);
    dictEntry *entry = d->table[idx];
    while (entry)
    {
        if (entry->key == key || (strcmp(entry->key, key) == 0)) {
            return entry->val;
        }
        entry = entry->next;
    }
    return NULL;
}

int dictDel(dict *d, void *key)
{
    int idx = IDX(d, key);
    dictEntry  *preEntry,*entry;
    preEntry = entry = d->table[idx];

    while(entry) {
       if (strcmp(entry->key, key) == 0) {
           if (entry == preEntry) {
               d->table[idx] = NULL;
           } else {
               preEntry->next = entry->next;
           }

           free(entry);
       }
       preEntry = entry;
       entry = entry->next;
    }
    return DICT_ERR;
}

int dictDisplay(dict *d)
{
    if (d) {
        if (d->table) {
            for (int i=0; i<d->size; i++) {
                dictEntry *entry = d->table[i];
                while (entry) {
                    info("key: %10s, val pointer %10s\n", entry->key, entry->val);
                    entry = entry->next;
                }
            }
            return DICT_OK;
        }
    }
    return DICT_ERR;
}

int dictClean(dict *d)
{
    if (d)
    {
        if (d->table)
        {
            for (int i=0; i<d->size; i++)
            {
                dictEntry *entry = d->table[i];
                dictEntry *tmp = NULL;
                while (entry) {
                    tmp = entry->next;
                    free(entry->key);
                    free(entry);
                    entry = tmp;
                }
            }
            free(d->table);
            d->table = NULL;
        }
        free(d);
    }

    return DICT_OK;
}


/*
int main(void)
{
    dict *d = dictCreate(8);
    int res = dictAdd(d, "name", (void*)"world");
    int res1 = dictAdd(d, "num",  (void*)10);
    int res2 = dictAdd(d, "name2", (void *) "10-111");

    printf("res: %d\n", res);
    printf("res: %d\n", res1);
    printf("res: %d\n", res2);

    void *val = dictGet(d, "name");
    void *val1 = dictGet(d, "num");
    void *val2 = dictGet(d, "name2");


    printf("val: %s\n", val);
    printf("val1: %d\n", (int)val1);
    printf("val2: %s\n", val2);


    dictDisplay(d);

    dictDel(d, "num");

    dictDisplay(d);

    dictAdd(d, "name", "hello");
    void *val4 = dictGet(d, "name");
    printf("val4: %s\n", val4);

    dictDisplay(d);

    dictClean(d);
    int res5 = dictDisplay(d);
    printf("res5: %d\n", res5);

    return 0;
}
*/
