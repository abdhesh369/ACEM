#include<stdio.h>
#include<conio.h>
int main()
//void main()
{
    float a,b,c,d;
    a= sizeof(char);
    b= sizeof(float);
    c=sizeof(double);
    d=sizeof(long double);
    printf("size of char=%f\n",a);
    printf("size of float=%f\n",b);
    printf("size of double=%f\n",c);
    printf("size of long double=%f\n",d);

//getch();
return 0;
}