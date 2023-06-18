#include <stdio.h>

int main(void) {
    int num1 = 1234;
    printf("num: %d\n", num1);

    /* 暗黙的型変換 */
    int num2 = 3;
    double dbl2;
    /* double型変数にint型変数を代入 */
    dbl2 = num2;
    printf("double型変数dblの値は: %lf\n", dbl2);
    /* int型の変数が式中でdouble型に変換 */
    double result2;
    result2 = dbl2 + num2;
    printf("double型変数resultの値は: %lf\n", result2);

    /* 明示的な型変換 */
    int num3 = 3;
    double dbl3;
    /* double型変数にint型変数を代入 */
    dbl3 = (double) num3;
    printf("double型変数dblの値は: %lf\n", dbl3);
    /* キャストしないことによる割り算でのエラー */
    double result3;
    result3 = 1 / num3;
    printf("double型変数resultの値は: %lf\n", result3);
    /* キャストによる割り算でのエラー回避 */
    double result31;
    result31 = 1 / (double) num3;
    printf("double型変数resultの値は: %lf\n", result31);

    /* キャストによる小数点以下切り捨てエラー */
    double dbl4 = 3.14;
    int num4;
    num4 = (int) dbl4;
    printf("int型変数numの値は: %d\n", num4);

    /* キャストによる符号付き整数のエラー */
    int num5 = -3;
    unsigned int unum5;
    unum5 = (unsigned int) num5;
    printf("unsigned int型変数unumの値は: %u\n", unum5);

    /* キャストによるオーバーフローのエラー */
    int num6 = 300;
    unsigned char unum6;
    unum6 = (unsigned char) num6;
    printf("unsigned char型変数unumの値は: %u\n", unum6);

    /* char型とint型の相互変換 */
    char c1 = 'A';
    int i1;
    i1 = (int) c1;
    printf("int型変数i1の値は: %d\n", i1);
    char c2;
    c2 = (char) i1;
    printf("char型変数c2の値は: %c\n", c2);

    /* const */
    const int num12 = 123;
    printf("num12: %d\n", num12);

    return 0;
}