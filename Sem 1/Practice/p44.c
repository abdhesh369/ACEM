#include <stdio.h>
#include <string.h>
int main()
{
    char sentance[99];
    char sentance1[99];
    printf("enter your first sentance:\n");
    fgets(sentance, sizeof(sentance), stdin);
    sentance[strcspn(sentance, "\n")] = '\0';
    printf("enter your second sentance:\n");
    fgets(sentance1, sizeof(sentance1), stdin);
    sentance1[strcspn(sentance1, "\n")] = '\0';
    printf("You entered:\n%s\n", strcat(sentance, sentance1));
    return 0;
}