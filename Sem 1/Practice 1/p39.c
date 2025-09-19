#include <stdio.h>
void isprime(int x)
{
    if (x % 2 == 0)
    {

        printf("%d is the prime number\n", x);
    }
    else
    {
        printf("%d is the not prime number\n", x);
    }
}
int main()
{
    int a;
    printf("enter the number: \n");
    scanf("%d", &a);
    isprime(a);
    return 0;
}