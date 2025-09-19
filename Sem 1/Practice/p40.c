#include <stdio.h>
int isprime(int a)
{
    if (a <= 1)
    {
        return 0;
    }
    for (int i = 2; i <= a / 2; i++)
    {
        if (a % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n;
    printf("Enter the number of element\n");
    scanf("%d", &n);
    int arr[n];
    int arr1[n];

    int result,k, sum = 0, x = 0;
    printf("Enter the numbers\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        result = isprime(arr[i]);
        if (result)
        {
            arr1[x] = arr[i];
            sum += arr[i];
            x++;
        }
    }
    printf("prime number in array are:");
    for (int i = 0; i < x; i++)
    {
        printf("%d,", arr1[i]);
    }
    printf("\nthe sum of prime number is:%d\n", sum);
    printf("the number of prime number is:%d\n", x);
    return 0;
}