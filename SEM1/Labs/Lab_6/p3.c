#include<stdio.h>
int main()
//void main()
{
    int i, j, temp, element[10];
printf("Enter elements of arrays\n");
for (i = 0; i < 10; i++) {
    scanf("%d", &element[i]);
}
for (i=0;i<10;i++)
{
    for(j=0;j<9-i;j++)
    {
        if(element[j]>element[j+1])
        {
           temp=element[j];
           element[j]=element[j+1];
           element[j+1]=temp;
        }
    }
}
printf("sorted array=\n");
for (i = 0; i < 10; i++) {
    printf("%d\n", element[i]);
}
 
//getch();
return 0;
}