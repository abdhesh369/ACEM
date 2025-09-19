#include <stdio.h>
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
int main()
{
    int result, a;
    printf("enter the number: \n");
    scanf("%d", &a);
    result = isprime(a);

    if (result)
    {

        printf("%d is the prime number\n", a);
    }
    else
    {
        printf("%d is the not prime number\n", a);
    }

    return 0;
}