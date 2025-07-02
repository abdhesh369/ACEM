#include<stdio.h>
int main()
//void main()
{
    int x,y, result, a;
printf("enter two number\n");
scanf("%d%d",&x, &y);
printf("choose operation\n");
printf("1.add\n2.subtract\n3.multiply\n4.divide\n");
scanf("%d",&a);
switch(a){
case 1:
result = x + y;
break;

case 2:
result = x-y;
break;

case 3:
result = x*y;
break;

case 4:
if (y != 0) {
    result = x / y;
} else {
    printf("Error: Division by zero\n");
    return 1;
}
break;
default:
    printf("Invalid operation\n");
    return 1;
}
printf("result=%d\n", result);
//getch();
return 0;
}