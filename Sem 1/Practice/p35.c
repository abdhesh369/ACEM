#include <stdio.h>
int main()
{
    int x, y, k = 1;
    printf("enter the number of rows and columns:\n");
    scanf("%d%d", &x, &y);

    int arr[x][y];
    int arr1[y][x];

    printf("Enter array's numbers:\n");
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            arr1[i][j] = arr[j][i];
        }
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (arr1[i][j] != arr[i][j])

            {
                k = 0;
            };
        }
    }
    if (k)
    {
        printf("it is  symatrix");
    }
    else
    {
        printf("it is not symatrix");
    }

    return 0;
}
