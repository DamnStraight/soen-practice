#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H

#include <stdbool.h>

//  Forward declaration so our node can define a pointer to itself
typedef struct Node Node;

struct Node {
    int data;
    struct Node *next;
};

/**
 * Singly linked list
 */
typedef struct {
    int size;
    Node *head;
} LinkedList;

LinkedList *LinkedList_new();

int LinkedList_get(LinkedList *list, int index);

void LinkedList_insertAt(LinkedList *list, int index, int value);

void LinkedList_removeAt(LinkedList *list, int index);

void LinkedList_remove(LinkedList *list, int value);

void LinkedList_push(LinkedList *list, int value);

void LinkedList_print(LinkedList *list);

int LinkedList_size(LinkedList *list);

bool LinkedList_isEmpty(LinkedList *list);

#endif //LINKED_LIST_LINKED_LIST_H
