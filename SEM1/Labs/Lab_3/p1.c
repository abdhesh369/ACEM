#include<stdio.h>
int main()
//void main()
{
    char a;
printf("Enter an alphabet\n");
scanf("%c",&a);
if (a >= 97 && a <= 122)
{
    a = a - 32;
}
else
{
    a = a + 32;
}
printf("Reversed alphabet=%c\n", a);
return 0;
}