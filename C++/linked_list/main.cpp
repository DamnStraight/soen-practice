#include <iostream>

#include "LinkedList.h"

int main() {
//    auto *list = new LinkedList<int>();
//
//    list->insertAt(0, 1);
//
//    list->push(4);
//
//    list->print();

    LinkedList<int> list;
    list.push(4);
    list.print();
    list.insertAt(0, 1);
    list.print();

    list.print();

    return 0;
}
