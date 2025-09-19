#include <stdio.h>
void differance(int x,int y)
{
    printf("The differance of number %d and %d is: %d \n\n",x,y,x-y);
}
int main()
{
    int a=10,b=8;
    differance(a,b);
    return 0;
}