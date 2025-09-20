#include <stdio.h>
#include<string.h>
int main()
{
    char sentance[99];
    char sentance1[99];
    printf("enter your sentance:\n");
    fgets(sentance, sizeof(sentance), stdin);
    sentance[strcspn(sentance,"\n")]='\0';
    printf("You entered:\n%s\n", sentance);
    return 0;
}