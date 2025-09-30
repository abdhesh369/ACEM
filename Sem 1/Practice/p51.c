// Write a program to swap the values of two variables using pass by reference.
#include <stdio.h>
void swapnum(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int a, b;
    printf("Enter two number:\n");
    scanf("%d%d", &a, &b);
    printf("Nunbers before swap are %d: %d\n", a, b);
    swapnum(&a, &b);
    printf("Nunbers  after swap are %d: %d\n", a, b);
    return 0;
}
