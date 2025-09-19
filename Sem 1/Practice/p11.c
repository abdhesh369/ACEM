#include <stdio.h>

int main()
{
    int num;
    printf("Enter a number:\n");
    scanf("%d", &num);

    if (num % 2 == 0)
    {
        printf("It is even.\n");
    }
    else
    {
        printf("It is odd.\n");
    }

    return 0;
}