#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

Node *new_node(int value) {
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

    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    lastNode->next = node;
    list->size++;
}

int LinkedList_get(LinkedList *list, int index) {
    if (index < 0 || index >= list->size) {
        perror("Index out of bounds");
        exit(EXIT_FAILURE);
    }

    if (index == 0) return list->head->data;

    Node* traversalNode = list->head;
    int traversalIndex = 0;

    while (traversalIndex != index) {
        traversalNode = traversalNode->next;
        traversalIndex++;
    }

    return traversalNode->data;
}

void LinkedList_insertAt(LinkedList *list, int index, int value) {
    if (index < 0 || index >= list->size) {
        if (list->size == index) {
            // If the size matches the index, we are essentially doing a push operation
            LinkedList_push(list, value);
            return;
        }
        perror("Index out of bounds");
        exit(EXIT_FAILURE);
    }

    Node *insertNode = new_node(value);

    if (index == 0) {
        insertNode->next = list->head;
        list->head = insertNode;
    } else {
        Node *traversalNode = list->head;
        int traversalIndex = 0;

        while (traversalNode->next != NULL && traversalIndex != (index - 1)) {
            traversalNode = traversalNode->next;
            traversalIndex++;
        }

        insertNode->next = traversalNode->next;
        traversalNode->next = insertNode;
    }

    list->size++;
}

void LinkedList_removeAt(LinkedList *list, int index) {
    if (index < 0 || index >= list->size) {
        perror("Index out of bounds");
        exit(EXIT_FAILURE);
    }

    Node *temp;

    if (index == 0) {
        if (list->size == 1) {
            list->head = NULL;
        } else {
            temp = list->head;
            list->head = temp->next;
            free(temp);
        }
        list->size--;
        return;
    }

    Node *traversalNode = list->head;
    int traversalIndex = 0;

    while (traversalIndex != (index - 1)) {
        traversalNode = traversalNode->next;
        traversalIndex++;
    }

    temp = traversalNode->next;

    // Then it's the last node
    if (temp->next == NULL) {
        traversalNode->next = NULL;
    } else {
        traversalNode->next = temp->next;
    }

    free(temp);
    list->size--;
}

int LinkedList_size(LinkedList *list) {
    return list->size;
}

bool LinkedList_isEmpty(LinkedList *list) {
    return list->size == 0;
}

void LinkedList_print(LinkedList *list) {
    Node *head = list->head;

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