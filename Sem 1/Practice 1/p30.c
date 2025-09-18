#include <stdio.h>
int main()
{
    int x, y;
    printf("enter the number rows and columns;\n");
    scanf("%d%d", &x, &y);

    int arr[x][y];
    printf("Enter  numbers:\n");
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Matrix:\n");
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
