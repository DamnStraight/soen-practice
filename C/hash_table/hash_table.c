#include "hash_table.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

//https://github.com/jamesroutley/write-a-hash-table

const int HT_PRIME_1 = 173;
const int HT_PRIME_2 = 811;

static ht_item HT_DELETED_ITEM = { NULL, NULL };

static ht_item *ht_new_item(const char *key, const char *value) {
    ht_item *new_item = malloc(sizeof(ht_item));
    new_item->key = strdup(key);
    new_item->value = strdup(value);
    return new_item;
}

hash_table *ht_new() {
    hash_table *new_table = malloc(sizeof(hash_table));
    new_table->size = 53;
    new_table->count = 0;
    new_table->items = calloc((size_t) new_table->size, sizeof(ht_item *));
    return new_table;
}

static void ht_delete_item(ht_item *item) {
    free(item->key);
    free(item->value);
    free(item);
}

void ht_delete_table(hash_table *table) {
    for (int i = 0; i < table->size; i++) {
        ht_item *item = table->items[i];
        if (item != NULL) {
            ht_delete_item(item);
        }
    }

    free(table->items);
    free(table);
}

static int ht_hash(const char *s, const int a, const int m) {
    long hash = 0;
    const unsigned int len_s = strlen(s);

    for (int i = 0; i < len_s; i++) {
        hash += (long) pow(a, len_s - (i + 1)) * s[i];
        hash = hash % m;
    }

    return (int) hash;
}

static int ht_get_hash(
        const char *s, const int num_buckets, const int attempt
) {
    const int hash_a = ht_hash(s, HT_PRIME_1, num_buckets);
    const int hash_b = ht_hash(s, HT_PRIME_1, num_buckets);
    return (hash_a + (attempt * (hash_b + 1))) % num_buckets;
}

void ht_insert(hash_table *table, const char *key, const char *val) {
    ht_item *new_item = ht_new_item(key, val);
    int index = ht_get_hash(new_item->key, table->size, 0);

    ht_item *maybe_item = table->items[index];

    int attempts = 1;
    // Keep hashing until we don't get a collision
    while (maybe_item != NULL) {
        if (maybe_item != &HT_DELETED_ITEM) {
            if (strcmp(key, maybe_item->key) == 0) {
                ht_delete_item(maybe_item);
                table->items[index] = new_item;
                return;
            }
        }
        index = ht_get_hash(new_item->key, table->size, attempts);
        maybe_item = table->items[index];
        attempts++;
    }

    table->items[index] = new_item;
    table->count++;
}

char *ht_search(hash_table *table, const char *key) {
    int index = ht_get_hash(key, table->size, 0);

    ht_item *maybe_item = table->items[index];

    int attempts = 1;
    while (maybe_item != NULL) {
        if (strcmp(key, maybe_item->key) == 0) {
            return maybe_item->value;
        }

        index = ht_get_hash(key, table->size, attempts);
        maybe_item = table->items[index];
        attempts++;
    }

    return NULL;
}

void ht_delete(hash_table *table, const char *key) {
    int index = ht_get_hash(key, table->size, 0);

    ht_item *maybe_item = table->items[index];

    int attempts = 1;
    while (maybe_item != NULL) {
        if (maybe_item != &HT_DELETED_ITEM) {
            if (strcmp(key, maybe_item->key) == 0) {
                ht_delete_item(maybe_item);
                table->items[index] = &HT_DELETED_ITEM;
            }
        }

        index = ht_get_hash(key, table->size, attempts);
        maybe_item = table->items[index];
        attempts++;
    }

    table->count--;
}