#include<stdio.h>
int main()
//void main()
{ 
    int i, n;
    printf("enter no. elements of array\n");
    scanf("%d",&n);
    int number[n];
    printf("enter elements of array\n");
    for(i=0;i<n;i++){
    scanf("%d",&number[i]);
    }
    for(i=0;i<n;i++){

    printf("elements of array=%d\n", number[i]);
    }
    return 0;
    }