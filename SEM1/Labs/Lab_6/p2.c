#include<stdio.h>
int main()
{
    int number[8], i, sum = 0;
    float average;
    printf("enters element\n");
    for(i=0;i<8;i++)
    {
        scanf("%d",&number[i]);
    }
     for(i=0;i<8;i++)
    {
       sum += number[i];
    }
average = (float)sum / 8;
printf("sum=%d\naverage=%.2f\n", sum, average);
return 0;
}