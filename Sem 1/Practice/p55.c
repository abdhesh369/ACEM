#include <stdio.h>
#include<string.h>

int main()
{
    char name[9] = "abdhesh";
    int len=strlen(name);
    for (int i =len-1; i>=0; i--)
    {
        for(int k=0;k<i;k++)
        {
            printf(" ");
        }
        
        for (int j = i; j<=len; j++)
        {
            printf("%c", name[j]);
        }
        printf("\n");
    }
    return 0;
}
