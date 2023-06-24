#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;

    int sum = a + b;
    int sub = a - b;
    int mul = a * b;
    int div = a / b;

    int mod = a % b;

    int expt2 = a << 2;
    int divexpt2 = a >> 2;

    int and = a & b;
    int or = a | b;
    int xor = a ^ b;
    int not = ~a;

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    printf("sum = %d\n", sum);
    printf("sub = %d\n", sub);
    printf("mul = %d\n", mul);
    printf("div = %d\n",div);

    printf("mod = %d\n", mod);

    printf("expt2 = %d\n", expt2);
    printf("divexpt2 = %d\n", divexpt2);

    printf("and = %d\n", and);
    printf("or = %d\n", or);
    printf("xor = %d\n", xor);
    printf("not = %d\n", not);

}
