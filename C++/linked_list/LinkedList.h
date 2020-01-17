#ifndef LINKED_LIST_LINKEDLIST_H
#define LINKED_LIST_LINKEDLIST_H

#include <memory>
#include <iostream>

template<typename T>
class LinkedList {
    class Node {
    public:
        T value;
        Node *next;

        explicit Node(T value) {
            this->value = value;
            this->next = nullptr;
        }

        Node(T value, Node *next) {
            this->value = value;
            this->next = next;
        }

        ~Node() {
            std::cout << "Deleted Node" << std::endl;
        }
    };

    Node *head = nullptr;
    int size = 0;

public:
    LinkedList() {}

    void removeAt() {

    }

    void insertAt(int index, T value) {
        // index is out of bounds
        if (index < 0 || index >= this->size) {
            // If list is empty, and insertion at 0
            if (index == 0) {
                // Add as head
                head = new Node(value);
                size++;
                return;
            }
            throw "Out of bounds";
        }

        Node *newNode = new Node(value);

        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {

            Node *traversalNode = head;
            int traversalIndex = 0;

            // perform regular insertion
            while (traversalIndex != (index - 1)) {
                traversalNode = traversalNode->next;
                traversalIndex++;
            }

            if (traversalNode->next->next != nullptr) {
                newNode->next = traversalNode->next->next;
            }
            traversalNode->next = newNode;
        }
        size++;
    }

    void push(T value) {
        Node *traversalNode = head;
        Node *newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            while (traversalNode->next != nullptr) {
                traversalNode = traversalNode->next;
            }
            traversalNode->next = newNode;
        }
        size++;
    }

    T getValue(Node *node) {
        return node->value;
    }

    void print() {
        Node *traversalNode = head;

        std::cout << "{ ";
        while (traversalNode != nullptr) {
            std::cout << traversalNode->value << ", ";
            traversalNode = traversalNode->next;
        }
        std::cout << "}" << std::endl;
    }
};

#endif //LINKED_LIST_LINKEDLIST_H
