#include <stdio.h>
int main()
{
    int n, sum = 0;
    printf("Enter the size of arry :\n ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the element of array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    printf("sum of array=%d\n", sum);
    printf("Average of array=%.2f\n", (float)sum / n);
    return 0;
}