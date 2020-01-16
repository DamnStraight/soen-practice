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
 * Increases the array capacity based on size to capacity comparison. O(n)
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

/**
 * Inserts value at given index - O(n)
 *
 * @param arr
 * @param index
 * @param val
 */
void ArrayList_insertAt(ArrayList *arr, int index, int val) {
    // If the endex is greater than the array size, index is OOB
    if (index > arr->size) {
        perror("Index out of bounds");
        exit(EXIT_FAILURE);
    }

    resize(arr, arr->size + 1);

    int *newArray = malloc(sizeof(int) * arr->capacity);

    for (int i = 0; i < arr->size; i++) {
        if (i == index) {
            newArray[i] = val;
        } else if (i > index) {
            newArray[i] = arr->data[i - 1];
        } else {
            newArray[i] = arr->data[i];
        }
    }

    free(arr->data);
    arr->data = newArray;
}

int ArrayList_removeAt(ArrayList *arr, int index) {
    if (arr->size == 0) {
        perror("Empty array");
        exit(EXIT_FAILURE);
    }

    for (int i = index; i < (arr->size - 1); i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}

void ArrayList_remove(ArrayList *arr, int val) {
    int elementIndex = -1;

    for (int i = 0; i < arr->size; i++) {
        if (arr->data[i] == val) {
            elementIndex = i;
        }
    }

    if (elementIndex == -1) return;

    for (int i = elementIndex; i < (arr->size - 1); i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}

void ArrayList_print(ArrayList *arr) {
    printf("{ ");
    for (int i = 0; i < arr->size; i++) {
        printf("%d%s", arr->data[i], (i == arr->size - 1) ? "" : ",");
    }
    printf(" }\n");
}

/**
 * Get element at index - O(1)
 *
 * @param arr
 * @param index
 * @return
 */
int ArrayList_get(ArrayList *arr, int index) {
    // If the endex is greater than the array size, index is OOB
    if (index > arr->size) {
        perror("Index out of bounds");
        exit(EXIT_FAILURE);
    }

    return arr->data[index];
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
