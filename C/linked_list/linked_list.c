#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

Node* new_node(int value) {
    Node *node = malloc(sizeof(LinkedList));
    node->data = value;
    node->next = NULL;
    return node;
}

LinkedList *LinkedList_new() {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->size = 0;
    list->head = NULL;
    return list;
}

void LinkedList_push(LinkedList *list, int value) {
    Node *node = new_node(value);

    if (list->size == 0) {
        list->head = node;
        list->size++;
        return;
    }

    Node *lastNode = list->head;

    while(lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    lastNode->next = node;
    list->size++;
}

void LinkedList_print(LinkedList *list) {
    Node* head = list->head;

    if (head == NULL) return;

    int index = 1;

    printf("{ ");
    while (head != NULL) {
        printf("%d%s", head->data, (index == list->size) ? "" : ", ");

        head = head->next;
        index++;
    }
    printf(" }\n");
}