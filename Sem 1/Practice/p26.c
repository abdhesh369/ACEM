#include <stdio.h>
int main()
{
    int n, x,y=0, min;
    printf("Enter the size of arry :\n ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the element of array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("enter the element you want to search:\n");
    scanf("%d", &x);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            printf("Your searched element is found:%d\n", arr[i]);
             y=1;
        }
    }
    if(!y)
    {
        printf("not found");
    }

    return 0;
}