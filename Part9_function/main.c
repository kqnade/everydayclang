#include <stdio.h>

int get_sum(int a, int b) {
    return a + b;
}

int main() {
    int x = 1;
    int y = 2;
    int z = get_sum(x, y);
    printf("Sum of %d and %d is %d\n", x, y, z);
}