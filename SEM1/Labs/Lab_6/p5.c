#include<stdio.h>
int main()
//void main()
{
    int n;
    printf("enter the size of matrix:\n");
    scanf("%d",&n);
    int matrix[n][n],i, j, min;
printf("enter the element of matrix\n");
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
    scanf("%d",&matrix[i][j]);
    }
}
printf("matrix is:\n");
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
    printf("%d\t",matrix[i][j]);
    }
    printf("\n");
}
min=matrix[0][0];
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        if(matrix[i][j]<=min)
        {
            min=matrix[i][j];
        }
    }
}
    for(i = 0; i < n; i++)
     {
        matrix[i][i] = min;        
        matrix[i][i] = min;
    }

    printf("Modified Matrix:\n");
    for(i = 0; i < n; i++)
     {
        for(j = 0; j < n; j++) 
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
     }

 return 0;
}