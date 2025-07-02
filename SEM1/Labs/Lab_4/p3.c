#include<stdio.h>
#include<conio.h>
int main()
//void main()
{
    int a=0, b=1, c, i,n;
printf("enter a range\n");
scanf("%d",&n);
for ( i = 0; i <n; i++)
{
   c=a+b;
   a=b;
   b=c;
printf("=%d\n",c);
}
//getch();
return 0;
}