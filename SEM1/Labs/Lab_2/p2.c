#include<stdio.h>
#include<conio.h>
int main()
//void main()
{
    int a,b,temp;
printf("enter two number\n");
scanf("%d%d",&a, &b);
printf("a=%d\nb=%d\n",a,b);
temp=a;
a=b;
b=temp;
printf("a=%d\nb=%d",a,b);
//getch();
return 0;
}