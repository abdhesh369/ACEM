#include <stdio.h>

int main()
{
    int num, num1, i;
    printf("Enter a number :\n");
    scanf("%d", &num);
    printf("Enter range of multiple :\n");
    scanf("%d", &num1);
    for (i = 1; i <= num1; i++)
    {
        printf("%d*%d=%d\n", num, i, num * i);
    }
    return 0;
}