#include<stdio.h>
#include<conio.h>
int main()
//void main()
{
    float a;
printf("Enter a number:");
scanf("%f",&a);
if (a<0)
 {
   printf("%f is negative",a);
 }
   else if (a>0)
   {
    printf("%f is positive",a);
   }
  else
    {
    printf("%f is zero",a);
    }
//getch();
return 0;
}