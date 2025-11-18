#include <stdio.h>

int main()
{
    int x;
    printf("Enter a number:\n");
    scanf("%d", &x);
    if (x > 0)
    {
        printf("It isa positive number.\n");
        if (x % 2 == 0)
            printf("It is even number.\n");
        else
            printf("It is odd number.\n");
    }
    else if (x < 0)
    {
        printf("It is negative number.\n");
        if (x % 2 == 0)
            printf("It is even number.\n");
        else
            printf("It is odd number.\n");
    }

    else
    {
        printf("It is zero.\n");
    }
    return 0;
}
