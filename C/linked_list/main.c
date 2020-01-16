#include <stdio.h>

#include "linked_list.h"

int main() {
    LinkedList *list = LinkedList_new();

    LinkedList_push(list, 1);

    LinkedList_print(list);
    LinkedList_push(list, 2);
    LinkedList_push(list, 3);
    LinkedList_push(list, 4);

    LinkedList_insertAt(list, 0, 77);
    LinkedList_insertAt(list, 1, 7);
    LinkedList_insertAt(list, list->size, 777);

    printf(" Found %d \n", LinkedList_get(list, list->size - 1));

    LinkedList_print(list);

    LinkedList_removeAt(list, 0);

    LinkedList_print(list);

    LinkedList_remove(list, 777);
    LinkedList_remove(list, 7);

    LinkedList_print(list);

    return 0;
}
