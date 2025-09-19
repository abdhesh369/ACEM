#include <stdio.h>
int main()
{
    int x, y, k = 0;
    printf("enter the number of rows and columns:\n");
    scanf("%d%d", &x, &y);
    if (x != y)

    {
        printf("it is not square matrix\n");
    }
    else
    {

        int arr[x][y];

        printf("Enter array's numbers:\n");
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (i == j && arr[i][j] != 1)
                {
                    k = 0;
                }
                if (i != j && arr[i][j] != 0)
                {
                    k = 0;
                }
            }
        }
        if (k)
        {
            printf("It is identity\n");
        }
        else
        {
            printf("It is not identity\n");
        }
    }
    return 0;
}
