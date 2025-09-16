#include <stdio.h>

int main()
{
    int num, num1 = 0, i;
    printf("Enter a number :\n");
    scanf("%d", &num);
    for (i = 1; i <= num;i++)
    {
        num1 += i;
    }
    printf("%d\n", num1);
    return 0;
}