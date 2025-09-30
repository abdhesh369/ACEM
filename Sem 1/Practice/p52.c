// Write a recursive function to generate particular term in Fibonacci series
#include <stdio.h>
int fibonacci(int a)
{
    if (a == 0)
    {
        return 0;
    }
    else if (a == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(a - 1) + fibonacci(a - 2);
    }
}

int main()
{
    int x;
    printf("Enter a range of fibonacci number\n");
    scanf("%d", &x);
    int arr[x];
    if (x < 0)
    {
        printf("Invalid range:\n");
    }
    else
    {
        for (int i = 0; i < x; i++)
        {
            arr[i] = fibonacci(i);
        }
        printf("Fibonacci number upto %d are :\n", x);
        for (int i = 0; i < x; i++)
        {

            printf("%d ", arr[i]);
        }
    }

    return 0;
}
