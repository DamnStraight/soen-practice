#include <stdlib.h>
#include "arraylist.h"

ArrayList *ArrayList_new(int capacity) {
    ArrayList *arr = malloc(sizeof(ArrayList));

    arr -> capacity = capacity;
    arr -> size = 0;

    arr -> data = malloc(sizeof(int) * capacity);

    return arr;
}

void ArrayList_push(ArrayList *arr, int val) {
    // TODO If full resize
    if (arr->size + 1 == arr->capacity) {

    } else {
        *(arr->data + arr->size) = val;
        arr->size++;
    }
}

int ArrayList_pop(ArrayList *arr) {
    if (arr->size == 0) {
        perror("ArrayList is empty");
        exit(EXIT_FAILURE);
    }

    --arr->size;
    return *(arr->data + arr->size);

}

#include "arraylist.h"
