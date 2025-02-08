#include<stdio.h>
int main()
//void main()
{
    int matrix[2][2],i, j, min;
printf("enter the element of matrix\n");
for(i=0;i<2;i++)
{
    for(j=0;j<2;j++)
    {
    scanf("%d",&matrix[i][j]);
    }
}
min=matrix[0][0];
for(i=0;i<2;i++)
{
    for(j=0;j<2;j++)
    {
        if(matrix[i][j]<=min)
        {
            min=matrix[i][j];
        }
    }
}
    for(i = 0; i < 2; i++)
     {
        matrix[i][i] = min;        
        matrix[i][1] = min;
    }

    printf("Modified Matrix:\n");
    for(i = 0; i < 2; i++)
     {
        for(j = 0; j < 2; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
     }

 return 0;
}