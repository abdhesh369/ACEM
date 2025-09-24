#include <stdio.h>
int main()
{
    float z,x,c,v,b,sum ,average;
    printf("Enter the five numbers:\n");
    scanf("%f%f%f%f%f", &z,&x,&c,&v,&b);
    sum=z+x+c+v+b;
    average=(z+x+c+v+b)/5;
    printf("The sum of five number is: %0.2f\n",sum);
    printf("The average  of five number is: %0.2f",average);
    return 0;
}