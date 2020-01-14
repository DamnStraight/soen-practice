#include <stdio.h>

int main() {
    // integer value
    int i = 7;

    // p is a pointer to an integer type
    int* p;

    // To get the address of a value, we use &
    p = &i;

    // We can return the pointer to a value using * like so:
    int i2 = *p;
    printf("Value at *p: %d\n", i2);

    // Arrays
    int a[2] = { 4, 5 };
    // We can access array values in two ways:
    // a[0] == *a
    // a[1] == *(a + 1)
    int ia = a[1];
    int ia2 = *(a + 1);

    printf("Value at a[1]: %d, value at *(a + 1): %d", ia, ia2);
    return 0;
}
