#include<stdio.h>
int add(int a,int b) 
{
return a+b;
}
int sub(int a, int b)
{
    return a-b;
}

int multi(int a, int b)
{
    return a*b;
}
float divide(int a, int b)
{
    return (float) a / b;
}
int main()

{
    int x, y;
printf("Enter two integers\n");
scanf("%d%d",&x, &y);
printf("sum=%d\n",add( x, y));
printf("sub=%d\n",sub( x, y));
printf("multiple=%d\n",multi( x, y));
if(y!=0)
{
printf("division=%.2f\n",divide( x, y));
}
//getch();
return 0;
}