#include <stdio.h>

int main()
{
    int num, num1, i;
    printf("Enter a starting number :\n");
    scanf("%d", &num);
    printf("Enter the range of ending  :\n");
    scanf("%d", &num1);
    if (num < num1)
    {
        printf("even number are:\n");
        for (i = num; i <= num1; i++)
        {
            if (i % 2 == 0)
            {
                printf("%d\n",i );
            }
        }
    }
    else
    {
        printf("invalid range\n");
    }
    
    return 0;
}