#include<stdio.h>
#include<conio.h>
int main()
//void main()
{
    int n,a,b,c,rev;
printf("Enter three digit number\n");
scanf("%d",&n);
printf("forward numberis=%d\n",n);
a=n/100;
b=(n%100)/10;
c=(n%10);
rev=c*100+b*10+a;
printf("reverse number is=%d\n",rev);
//getch();
return 0;
}