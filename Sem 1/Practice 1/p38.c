#include <stdio.h>
void cube(int x)
{
    printf("The cube of number %d is: %d \n\n",x,x*x*x);
}
int main()
{
    int a=10;
    cube(a);
    return 0;
}