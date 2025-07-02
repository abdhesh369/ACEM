#include<stdio.h>
#include<conio.h>
int isprime(int a)
{
  for(int i=2;i<a;i++)
  if (a%i==0)
  {
    return 1;
  }
  else
  return 0;
  
}
int main()
//void main()
{
    int num;
printf("enter a number\n");
scanf("%d", &num);
if (isprime(num))
{
    printf("it is prime");
}
else 
printf("it is not prime");
//getch();
return 0;
}