#include <stdio.h>
int main()
{
    char sentance[99];
    printf("enter your sentance:\n");
    fgets(sentance, sizeof(sentance), stdin);
    printf("You entered:\n%s", sentance);
    return 0;
}