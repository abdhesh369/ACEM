#include <stdio.h>
void printMatrix(int n, int mat[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
int isprime(int x)
{
    if (x <= 1)
    {
        return 0;
    }
    else

        for (int i = 2; i <= x / 2; i++)
        {
            if (x % i == 0)
                return 0;
        }
    return 1;
}

int sumofprime(int x, int mat[x][x])
{
    int sum = 0;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (isprime(mat[i][j]))
            {
                sum += mat[i][j];
            }
        }
    }
    return sum;
}
int countPrimes(int n, int mat[n][n])
{
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isprime(mat[i][j]))
            {
                a++;
            }
        }
    }
    return a;
}

int isSymmetric(int n, int mat[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != mat[j][i])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int n, result;
    int result1;
    printf("Enter the size of matrix\n ");
    scanf("%d", &n);
    int arr[n][n];
    printf("Enter the element of matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printMatrix(n, arr);
    result = sumofprime(n, arr);
    printf("sum of prime number in matrix is %d", result);
    result1 = countPrimes(n, arr);
    printf("number of prime number in matrix is %d", result1);
    if (isSymmetric(n, arr))
    {
        printf("It is a symatric Matrix ✅\n");
    }
    else
    {
        printf("It is NOT a symatric Matrix ❌\n");
    }
    return 0;
}
