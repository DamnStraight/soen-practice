#include <stdio.h>
#include "array.c"

int main() {
    Array *arr = Array_new(32);
    Array_push(arr, 2);
    Array_push(arr, 3);

    printf("%d\n", *(arr->data + 1));
    return 0;
}
