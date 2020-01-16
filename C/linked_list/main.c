#include <stdio.h>

#include "linked_list.h"

int main() {
    LinkedList *list = LinkedList_new();

    LinkedList_push(list, 1);

    LinkedList_print(list);
    LinkedList_push(list, 2);
    LinkedList_push(list, 3);
    LinkedList_push(list, 4);

    LinkedList_print(list);

    return 0;
}
