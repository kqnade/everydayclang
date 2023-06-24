// get input and return output
# include <stdio.h>

// hello world
int main(void)
{
    // get two numbers from scanf input
    int x, y;
    printf("x: ");
    scanf("%i[0-9]", &x);
    printf("y: ");
    scanf("%i[0-9]", &y);

    // print two numbers each on a new line
    printf("x: %i\n", x);
    printf("y: %i\n", y);

    return 0;
}
