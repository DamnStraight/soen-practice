#include <iostream>

#include "ArrayList.h"

int main() {
    ArrayList<int> arr;

    arr.push(1);
    arr.push(2);
    arr.print();
    arr.pop();
    arr.print();

    for (int i = 0; i <= 34; i++) {
        arr.push(i);
    }

    arr.print();

    return 0;
}
