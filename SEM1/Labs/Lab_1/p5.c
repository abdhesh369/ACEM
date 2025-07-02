#include<stdio.h>
#include<conio.h>
int main()
//void main()
{
    float a,b,pi=3.14, area;
printf("Enter major axis \n");
scanf("%f",&a);
printf("Enter minor axis \n");
scanf("%f",&b);
area=pi*a*b;
printf("area=%f",area);
//getch();
return 0;
}
