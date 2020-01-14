#include <stdio.h>

int main() {
    int i;

    printf("Enter a number: ");
    // Store at variable address using &, not i directly!
    scanf("%d", &i);

    printf("\nYou entered: %d", i);

    return 0;
}
