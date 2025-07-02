#include<stdio.h>
#include<conio.h>
int main()
//void main()
{
    int n,a,b,c,rev;
printf("Enter a number\n");
scanf("%d",&n);
printf("forward number=%d\n",n);
a=n/100;
b=(n%100)/10;
c=n%10;
rev=c*100+b*10+a;
printf("reverse number=%d\n",rev);
if(n==rev)
printf("it is palindrome\n");
else
printf("it is not palindrome\n");
//getch();
return 0;
}