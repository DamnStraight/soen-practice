#ifndef ARRAY_ARRAY_H
#define ARRAY_ARRAY_H

static const short int MIN_CAPACITY = 32;

typedef struct {
    unsigned int size;
    int capacity;
    int *data;
} Array;

static Array *Array_new(int capacity);

static void Array_push(Array *arr, int val);

#endif //ARRAY_ARRAY_H
