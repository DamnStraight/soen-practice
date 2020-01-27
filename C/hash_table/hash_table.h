#ifndef HASH_TABLE_HASH_TABLE_H
#define HASH_TABLE_HASH_TABLE_H

typedef struct {
    char *key;
    char *value;
} ht_item;

typedef struct {
    int size;
    int count;
    ht_item **items;
} hash_table;

void ht_insert(hash_table* table, const char *key, const char *value);
char* ht_search(hash_table *table, const char *key);
void ht_delete(hash_table *table, const char *key);

#endif //HASH_TABLE_HASH_TABLE_H
