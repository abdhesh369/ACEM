#include <stdio.h>

int main()
{
    int num;
    printf("Enter a total marks in percentage(1-100) :\n");
    scanf("%d", &num);

    if (num >= 80)
    {
        printf("Distinction");
    }
    else if (num >= 40)
    {
        printf("Pass");
    }

    else
    {
        printf("Fail");
    }
    return 0;
}