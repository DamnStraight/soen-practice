#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H

//  Forward declaration so our node can define a pointer to itself
typedef struct Node Node;

struct Node {
    int data;
    struct Node* next;
};

typedef struct {
    int size;
    Node* head;
} LinkedList;

LinkedList *LinkedList_new();

void LinkedList_insert(LinkedList* list, int index, int value);

void LinkedList_push(LinkedList* list, int value);

void LinkedList_print(LinkedList* list);

#endif //LINKED_LIST_LINKED_LIST_H
