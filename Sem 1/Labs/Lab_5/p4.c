#include<stdio.h>
#include<conio.h>
int dectobin(int n)
{ 
    if (n>1)
{
    dectobin(n/2);
}
     printf("%d",n%2);
}
int main()
//void main()
{ 
    int n,dic, bin;
printf("Enter a decimal number\n");
scanf("%d",&n);
if (n==0)
{
   printf("binnary number is 0"); 
}
else
{
   printf("binnary number\n");   
   dectobin(n); 
}
//getch();
return 0;
}