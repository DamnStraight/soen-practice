#ifndef ARRAYLIST_ARRAYLIST_H
#define ARRAYLIST_ARRAYLIST_H

#include <stdbool.h>

typedef struct {
    int size;
    int capacity;
    int *data;
} ArrayList;

ArrayList *ArrayList_new();

void ArrayList_push(ArrayList *arr, int val);

int ArrayList_pop(ArrayList *arr);

void ArrayList_insertAt(ArrayList *arr, int index, int value);

void ArrayList_print(ArrayList *arr);

void ArrayList_removeAt(ArrayList *arr, int index);

int ArrayList_get(ArrayList *arr, int index);

int size(ArrayList *arr);

int capacity(ArrayList *arr);

bool is_empty(ArrayList *arr);

#endif //ARRAYLIST_ARRAYLIST_H
