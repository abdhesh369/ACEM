#include<stdio.h>
int main()
//void main()
{
    int a, b, lcm, hcf, i;
printf("Enter two integer:\n");
scanf("%d%d", &a, &b);
    for(i = 1; i <= a && i <= b; i++)
     {
        if(a % i == 0 && b % i == 0)
            hcf = i;
    }
    lcm = (a * b) / hcf;

    printf("lcm=%d\nhcf=%d\n", lcm, hcf);

    return 0;
}