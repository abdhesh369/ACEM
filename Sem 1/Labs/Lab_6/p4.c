#include <stdio.h>

int read(int a[], int n)
{
    printf("enter element of array\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
int sort(int a[], int n)
{
    int temp, i, j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(a[j] > a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int display(int a[], int n)
{
    printf("sorted array is\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }   
}
int main() 
{
    int n;
    printf("enter number of array\n");
    scanf("%d",&n);
    int a[n];
    read(a, n);
    sort(a, n);
    display(a, n);
    return 0;
}