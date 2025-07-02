#include<stdio.h>
#include<conio.h>
int main()
//void main()
{
    int p,r,t,si;
printf("Enter principal,rate,time\n");
scanf("%d%d%d",&p, &r,&t);
si=(p*r*t)/100;
printf("simple intrest=%d",si);
//getch();
return 0;
}