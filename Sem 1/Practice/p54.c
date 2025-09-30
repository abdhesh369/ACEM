#include <stdio.h>
void additon(int rows, int column, int matrix1[rows][column], int matrix2[rows][column],int matrix3[rows][column])
{

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < column; j++)
        {
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}
int main()
{
    int m, n;
    printf("Enter the size of first matrix(m *n)\n");
    scanf("%d%d", &m, &n);
    int arr1[m][n];
    printf("Enter the element of first matrix(m *n)\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
    int p, q;
    printf("Enter the size of second matrix(p *q)\n");
    scanf("%d%d", &p, &q);
    int arr2[p][q];
    printf("Enter the element of second matrix(p *q)\n");
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }
    int arr3[m][n];
    if (m == p && n == q)
    {
        additon(m, n, arr1, arr2,arr3);
        printf("Sum of matrices\n");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)

            {
                printf("%d ", arr3[i][j]);
            }
            printf("\n");
        }
    }

    else
    {
        printf("matrix diamension doesn't matched\n");
    }

    return 0;
}
