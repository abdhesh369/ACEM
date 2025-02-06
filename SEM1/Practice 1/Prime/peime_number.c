#include<stdio.h>
int main()
{
    int n, i, isPrime = 1;
    printf("Enter a number: ");
    scanf("%d", &n);
    
if (n <= 1) {
        isPrime = 0;
    } else {
        for (i = 2; i < n; i++) {
            if (n % i == 0) {
                isPrime = 0;
                printf("Not a prime number\n");
                break;
            }
        }
        if (isPrime) {
            printf("Prime number\n");
        }
    }
    
    return 0;
}