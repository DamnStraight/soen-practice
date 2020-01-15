#include <stdio.h>
#include "arraylist.h"

int main() {
    ArrayList *arr = ArrayList_new(32);
    ArrayList_push(arr, 2);
    ArrayList_push(arr, 3);
    printf("%d\n", *(arr->data + 1));
    printf("%d\n", ArrayList_pop(arr));
    printf("%d\n", ArrayList_pop(arr));

    for (int i = 0; i < 62; i++) {
        ArrayList_push(arr, i);
    }

    for (int i = 0; i < size(arr); i++) {
        printf("%d\n", arr->data[i]);
    }

    return 0;
}
