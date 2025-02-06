#include<stdio.h>
#include<conio.h>
int main()
//void main()
{
    int n;
printf("Enter a number\n");
scanf("%d",&n);
if(n%5==0)
{
    printf("it is multiple of 5\n");
}
else{
    printf("not\n");
}
if(n%7==0 && n%11!=0)
{
    printf("it is divisable by 7 but not by 11\n");

}
else
{
    printf("it is not divisable by 7 or diviasble by 11\n");
}
//getch();
return 0;
}