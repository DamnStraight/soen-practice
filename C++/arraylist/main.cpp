#include <iostream>

#include "ArrayList.h"

int main() {
    ArrayList<int> arr;

    arr.push(1);
    arr.push(2);
    arr.print();
    arr.pop();
    arr.print();

    return 0;
}
