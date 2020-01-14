#include <stdlib.h>
#include "array.h"

Array *Array_new(int capacity) {
    Array *arr = malloc(sizeof(Array));

    arr -> capacity = capacity;
    arr -> size = 0;

    arr -> data = malloc(sizeof(int) * capacity);

    return arr;
}

void Array_push(Array *arr, int val) {
    *(arr->data + arr->size) = val;
    arr->size++;
}

