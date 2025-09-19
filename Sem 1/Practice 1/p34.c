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
        printf("Upper part:\n");

        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (i < j || i == j)
                {
                    printf("%d ", arr[i][j]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf("\n");
        }
        printf("\n");
        printf("lower part\n");

        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                if (i < j || i == j)
                {
                    printf("%d ", arr[i][j]);
                }
                else
                {
                    printf("  ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
