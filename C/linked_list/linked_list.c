#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

/**
 * Allocate memory for a new node with given value
 * @param value
 * @return
 */
static Node *new_node(int value) {
    Node *node = malloc(sizeof(LinkedList));
    node->data = value;
    node->next = NULL;
    return node;
}

/**
 * Checks that the index doesn't go out of bounds otherwise throw an error
 */
static void isValid(int size, int index) {
    if (index < 0 || index > (size - 1)) {
        perror("Index out of bounds");
        exit(EXIT_FAILURE);
    }
}

/**
 * Retrieve a node by a given index (Does not handle OOB logic)
 */
static Node *get(LinkedList *list, int index) {
    Node *traversalNode = list->head;
    int traversalCounter = 0;

    while (traversalCounter <= list->size) {
        if (traversalCounter == index) return traversalNode;
        traversalNode = traversalNode->next;
        traversalCounter++;
    }

    return NULL;
}

/**
 * Create new LinkedList instance
 *
 * @return
 */
LinkedList *LinkedList_new() {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->size = 0;
    list->head = NULL;
    return list;
}

/**
 * Add an element to the end of the list
 *
 * @param list
 * @param value
 */
void LinkedList_push(LinkedList *list, int value) {
    Node *newNode = new_node(value);

    if (list->size == 0) {
        list->head = newNode;
    } else {
        Node *lastNode = get(list, list->size - 1);
        lastNode->next = newNode;
    }

    list->size++;
}

/**
 * Add an element to the front of the list
 *
 * @param list
 * @param value
 */
void ArrayList_unshift(LinkedList *list, int value) {
    if (list->size == 0) LinkedList_push(list, value);

    Node *newNode = new_node(value);
    newNode->next = list->head;
    list->head = newNode;

    list->size++;
}

/**
 * Retrieve the value stored at the given index
 *
 * @param list
 * @param index
 * @return
 */
int LinkedList_get(LinkedList *list, int index) {
    isValid(list->size, index);

    Node *result = get(list, index);
    return result->data;
}

/**
 * Insert an element at a given index
 *
 * @param list
 * @param index
 * @param value
 */
void LinkedList_insertAt(LinkedList *list, int index, int value) {
    isValid(list->size, index);

    // If the index is the last element of the list, perform a push operation
    if (index == list->size - 1)
        return LinkedList_push(list, value);
    // If the index is 0, perform an unshift
    if (index == 0)
        return ArrayList_unshift(list, value);

    Node *insertNode = new_node(value);
    Node *prevNode = get(list, index - 1);
    Node *nextNode = prevNode->next;

    prevNode->next = insertNode;
    insertNode->next = nextNode;

    list->size++;
}

/**
 * Remove element at given index
 *
 * @param list
 * @param index
 */
void LinkedList_removeAt(LinkedList *list, int index) {
    isValid(list->size, index);

    Node *deleteNode;

    // If there's only one element, it's the head
    if (list->size == 1) {
        deleteNode = list->head;
        list->head = NULL;
    } else {
        // If the index is 0,
        if (index == 0) {
            deleteNode = list->head;
            list->head = list->head->next;
        } else {
            // Get the node one position before the one we need to delete
            Node *prevNode = get(list, index - 1);

            // Store the pointer of our soon to be deleted node's next pointer
            Node *tempNode = prevNode->next->next;

            // Free memory and remove the node
            deleteNode = prevNode->next;

            // If the index is not the last element, we need to set the next pointer
            if (index != (list->size - 1)) {
                // Free memory and remove the node
                free(prevNode->next);
                // Set the
                prevNode->next = tempNode;
            }
        }
    }

    free(deleteNode);
    list->size--;
}

/**
 * Remove first element containing a matching value
 *
 * @param list
 * @param value
 */
void LinkedList_remove(LinkedList *list, int value) {
    if (list->size == 0) return;

    Node *traversalNode = list->head;
    Node *prevNode = NULL;

    while (traversalNode != NULL) {
        if (traversalNode->data == value) {
            // It's the head
            if (prevNode == NULL) {
                list->head = traversalNode->next;
            } else {
                if (traversalNode->next != NULL) {
                    prevNode->next = NULL;
                } else {
                    prevNode->next = traversalNode->next;
                }
            }

            list->size--;
            return free(traversalNode);
        }

        prevNode = traversalNode;
        traversalNode = traversalNode->next;
    }
}

/**
 * Return list size
 *
 * @param list
 * @return
 */
int LinkedList_size(LinkedList *list) {
    return list->size;
}

/**
 * Return whether the list is empty
 *
 * @param list
 * @return
 */
bool LinkedList_isEmpty(LinkedList *list) {
    return list->size == 0;
}

/**
 * Print all the elements in the array
 * @param list
 */
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