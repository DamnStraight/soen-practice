#include <stdio.h>
#include "arraylist.h"

int main() {
    ArrayList *arr = ArrayList_new(32);
    ArrayList_push(arr, 2);
    ArrayList_push(arr, 3);
    printf("%d\n", *(arr->data + 1));
    printf("%d\n", ArrayList_pop(arr));
    printf("%d\n", ArrayList_pop(arr));
    printf("%d\n", ArrayList_pop(arr));
    return 0;
}
