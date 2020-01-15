#include <stdlib.h>
#include <stdio.h>
#include "arraylist.h"

const unsigned short int GROWTH_FACTOR = 2;
const unsigned short int DEFAULT_CAPACITY = 32;

ArrayList *ArrayList_new() {
    ArrayList *arr = malloc(sizeof(ArrayList));

    arr->capacity = DEFAULT_CAPACITY;
    arr->size = 0;

    arr->data = malloc(sizeof(int) * DEFAULT_CAPACITY);

    return arr;
}

/**
 * Increases the array capacity based on size to capacity comparison.
 *
 */
void resize(ArrayList *arr, int size) {
    int newCapacity;

    // If we are about to reach cap, double the size
    if (arr->capacity == size) {
        newCapacity = arr->capacity * GROWTH_FACTOR;
        // Otherwise, check if we are using too little space
    } else {
        return;
    }

    printf("Resizing, current capacity = %d, new capacity = %d\n", arr->capacity, newCapacity);

    int *resizedData = malloc(sizeof(int) * newCapacity);

    for (int i = 0; i < arr->capacity; i++) {
        resizedData[i] = *(arr->data + i);
    }

    free(arr->data);
    arr->data = resizedData;
    arr->capacity = newCapacity;
}

/**
 * Insert an element as the end of the error - O(1)
 * @param arr
 * @param val
 */
void ArrayList_push(ArrayList *arr, int val) {
    resize(arr, arr->size + 1);

    *(arr->data + arr->size) = val;
    arr->size++;
}

/**
 * Remove and return the last element in the array - O(1)
 * @param arr
 * @return
 */
int ArrayList_pop(ArrayList *arr) {
    if (arr->size == 0) {
        perror("ArrayList is empty");
        exit(EXIT_FAILURE);
    }

    resize(arr, arr->size - 1);

    --arr->size;
    return *(arr->data + arr->size);
}

int peek(ArrayList *arr) {
    if (arr->size == 0) {
        perror("ArrayList is empty");
        exit(EXIT_FAILURE);
    }

    return *(arr->data + arr->size);
}

bool is_empty(ArrayList *arr) {
    return arr->size == 0;
}

int capacity(ArrayList *arr) {
    return arr->capacity;
}

int size(ArrayList *arr) {
    return arr->size;
}

#include "arraylist.h"
