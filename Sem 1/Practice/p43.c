#include <stdio.h>
#include<string.h>
int main()
{
    char sentance[99];
    printf("enter your sentance:\n");
    fgets(sentance, sizeof(sentance), stdin);
    sentance[strcspn(sentance,"\n")]='\0';
    printf("You entered:\n%s\n", sentance);
    printf("You entered sentance length is:\n%d", strlen(sentance));
    return 0;
}