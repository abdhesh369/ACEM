#include <stdio.h>
int main()
{
    int x, y,k=0;
    printf("enter the number of rows and columns:\n");
    scanf("%d%d", &x, &y);

    int arr[x][y];

    printf("Enter array's numbers:\n");
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = i; j < y; j++)
        {
            if(arr[i][i]==1&&arr[i][j]==0 )
            {
               printf("It is identity\n"); 
               k=1;
            }
        }
        
    }
    if(!k)
        {
             printf("It is not identity\n"); 
        }

    return 0;
}
