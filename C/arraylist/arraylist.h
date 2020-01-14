#ifndef ARRAYLIST_ARRAYLIST_H
#define ARRAYLIST_ARRAYLIST_H

#include <stdbool.h>

typedef struct {
    unsigned int size;
    int capacity;
    int *data;
} ArrayList;

ArrayList *ArrayList_new(int capacity);

void ArrayList_push(ArrayList *arr, int val);

int ArrayList_pop(ArrayList *arr);



int size(ArrayList *arr);

int capacity(ArrayList *arr);

bool is_empty(ArrayList *arr);

#endif //ARRAYLIST_ARRAYLIST_H
