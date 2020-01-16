#ifndef ARRAYLIST_ARRAYLIST_H
#define ARRAYLIST_ARRAYLIST_H

#include <stdio.h>
#include <malloc.h>

/**
 * List ADT implemented using arrays
 *
 * @tparam T
 */
template<typename T>
class ArrayList {
    static const int GROWTH_FACTOR = 2;
    static const int DEFAULT_CAPACITY = 32;

    int capacity;
    int size;
    T *data;

    void resize_expand() {
        int newCapacity = capacity * GROWTH_FACTOR;
        T *newArr = (T*) malloc(sizeof(T) * newCapacity);

        printf("Resizing from %d -> %d\n", capacity, newCapacity);

        for (int i = 0; i < size; i++) {
            newArr[i] = data[i];
        }

        free(this->data);
        this->capacity = newCapacity;
        this->data = newArr;
    }

public:
    ArrayList() {
        this->capacity = DEFAULT_CAPACITY;
        this->size = 0;
        this->data = (T*) malloc(sizeof(T) * this->capacity);
    }

    explicit ArrayList(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        this->data = (T*) malloc(sizeof(T) * this->capacity);
    };

    int get(int index) {
        return 0;
    };

    void insertAt(int index, T val) {
        if (index < 0 || index >= capacity) { throw "Index out of bounds"; };

        if (size + 1 == capacity) {
            resize_expand();
        }

        T *newArr = (T*) malloc(sizeof(int) * capacity);

        for (int i = 0; i < size; i++) {
            if (i < index) {
                newArr[i] = data[i];
            } else if (i == index) {
                newArr[i] = val
            } else {
                newArr[i] = data[i - 1];
            }
        }

        free(this->data);
        this->size++;
        this->data = newArr;
    };

    T removeAt(int index) {
        if (index < 0 || index >= capacity) { throw "Index out of bounds"; };

        T *newArr = (T*) malloc(sizeof(T) * capacity);

        for (int i = 0; i < size; i++) {
            if (i < index) {
                newArr[i] = data[i];
            } else if (i >= index) {
                newArr[i] = data[i + 1];
            }
        }

        this->size--;
    };

    T pop() {
        if (size == 0) { throw "No elements to pop"; };

        size--;
        return data[size];
    };

    void push(T val) {
        if (size + 1 == capacity) {
            resize_expand();
        }

        data[size] = val;
        size++;
    };

    int getSize() {
        return this->size;
    }

    int getCapacity() {
        return capacity;
    }

    bool isEmpty() {
        return (size == 0);
    }

    void print() {
        std::cout << "{ ";
        for (int i = 0; i < size; i++) {
            printf("%d%s", data[i], (i == size - 1) ? "" : ", ");
        }
        std::cout << " }" << std::endl;
    }
};


#endif //ARRAYLIST_ARRAYLIST_H
