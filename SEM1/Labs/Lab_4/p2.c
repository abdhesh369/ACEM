#include<stdio.h>
#include<conio.h>
int main()
//void main()
{
    int n1, n2, i, j, isPrime = 1;
    printf("Enter a starting point\n");
    scanf("%d",&n1);
    printf("Enter a ending point\n");
    scanf("%d",&n2);
    for (i = n1; i <= n2; i++) {
        if (i <= 1) {
            continue;
        }
        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime) {
            printf("%d is a prime number\n", i);
        }
    }
    //getch();
    return 0;
}
//getch();