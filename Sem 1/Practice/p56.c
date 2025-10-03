#include <stdio.h>
#include <string.h>

int main()
{
    int count=0;
    char name[9] = "abdhesh";
    for (int i = 6; i >=0; i--)
    {
        printf("%c \n", name[i]);
        count++;
    }
    printf("The number of letters in string %d\n",count);
    return 0;
}
