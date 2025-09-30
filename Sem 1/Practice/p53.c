// Write a program to calculate the sum of the series: 1+11+111+........+up to N terms using
// recursive function. If N is read as 5, the series is: 1+11+111+1111+11111.

#include <stdio.h>
int sum(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    else
    {
        return 10 * sum(n - 1) + 1;
    }
}
int main()
{
    int x,total=0;
    printf("Enter the range :\n");
    scanf("%d", &x);
    int arr[x];
    for (int i = 0; i < x; i++)
    {
        arr[i] = sum(i + 1);
        total +=arr[i];
    }
    for (int i = 0; i < x; i++)
    {
        printf("%d", arr[i]);
        if(i !=x-1)
        {
            printf("+");
        }
    }
    printf("\nTotal of the series is: %d\n",total);

    return 0;
}
