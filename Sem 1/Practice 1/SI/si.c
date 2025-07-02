#include<stdio.h>
#include<conio.h>
int main()
{
    float p,t,R,SI;
    printf("Enter principal\nrate\ntime\n");
    scanf("%f%f%f",&p,&t,&R);
    SI=(p*t*R)/100;
    printf("the simple interest is %f",SI);
   // getch();
    return 0;

}