#include <stdio.h>
#include "arraylist.h"

void test_push_pop() {
    ArrayList *arr = ArrayList_new();

    ArrayList_push(arr, 1);
    ArrayList_push(arr, 2);
    ArrayList_push(arr, 3);

    printf("%d\n", *(arr->data + 1));
    printf("%d\n", ArrayList_pop(arr));
    printf("%d\n", ArrayList_pop(arr));

    ArrayList_print(arr);
}

void test_resize_insert() {
    ArrayList *arr = ArrayList_new();

    // Should invoke a resize
    for (int i = 0; i < 62; i++) {
        ArrayList_push(arr, i);
    }

    ArrayList_print(arr);

    ArrayList_insertAt(arr, 1, 777);
    ArrayList_insertAt(arr, 4, 777);

    ArrayList_print(arr);

    ArrayList_removeAt(arr, 4);


}

int main() {
    test_push_pop();

    test_resize_insert();

    return 0;
}