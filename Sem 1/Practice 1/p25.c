#include <stdio.h>
int main()
{
    int n, min;
    printf("Enter the size of arry :\n ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the element of array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        min = arr[0];
        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    printf("Minimum of array=%d\n", min);
    return 0;
}