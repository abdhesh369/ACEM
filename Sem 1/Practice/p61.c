#include <stdio.h>

int main()
{
    int x, y, sum, product, difference;
    int division, remainder;
    printf("Enter two integer:\n");
    scanf("%d%d", &x, &y);

    sum = x + y;
    printf("The sum of two integer:%d\n", sum);
    difference = x - y;
    printf("The difference of two integer:%d\n", difference);
    product = x * y;
    printf("The product of two integer:%d\n", product);
    if (y != 0)
    {
        division = x / y;
        printf("The quotient of two integer:%d\n", division);
        remainder = x % y;
        printf("The remainder of two integer:%d\n", remainder);
    }
    else
    {
        printf("Error in division");
    }

    return 0;
}