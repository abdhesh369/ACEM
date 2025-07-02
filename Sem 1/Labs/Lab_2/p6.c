#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
//void main()
{
    int n, a,b,c,arm;
printf("Enter a number\n");
scanf("%d",&n);
a=n/100;
b=(n%100)/10;
c=n%10;
arm=pow(a,3)+pow(b,3)+pow(c,3);
if(n==arm)
printf("%d is armstrong number",n);
else
printf("%d is not armstrong number",n);
//getch();
return 0;
}