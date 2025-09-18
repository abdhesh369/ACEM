#include <stdio.h>
int main()
{
    int n, x = 0, y = 0, z = 0;
    printf("Enter the size of arry :\n ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the element of array: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] >= 1)
        {
            x++;
        }
        else if (arr[i] == 0)
        {
            y++;
        }

        else if (arr[i] <= -1)
        {
            z++;
        }
    }
    printf("The number of zero:%d\n",y);
    printf("The number of positive number:%d\n",x);
    printf("The number of negative number:%d\n",z);

    return 0;
}