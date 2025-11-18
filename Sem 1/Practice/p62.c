#include <stdio.h>

int main()
{
    int x, y, z;

    printf("Enter three number:\n");
    scanf("%d%d%d", &x, &y, &z);
    int largest = x;
    if (y > largest)
        largest = y;

    if (z > largest)
        largest = z;

    int smallest = x;
    if (y < smallest)
        smallest = y;

    if (z < smallest)
        smallest = z;

    printf("The largest number is: %d\n", largest);
    printf("The smallest number is: %d\n", smallest);
    return 0;
}
