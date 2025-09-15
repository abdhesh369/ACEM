#include <stdio.h>
int main()
{
    int x, y, sum, difference, product;
    float division;

    x = 50;
    y = 19;

    sum = x + y;
    difference = x - y;
    product = x * y;
    division = (float)x / y;

    printf("Sum = %d\n", sum);
    printf("Difference = %d\n", difference);
    printf("Product = %d\n", product);
    printf("Division = %.2f\n", division);

    return 0;
}
