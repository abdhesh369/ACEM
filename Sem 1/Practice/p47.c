#include <stdio.h>
#include <string.h>
int main()
{
    char sentance[99];
    char sentance1[99];
    char sentance2[99];

    printf("enter your first sentance:\n");
    fgets(sentance, sizeof(sentance), stdin);
    sentance[strcspn(sentance, "\n")] = '\0';

    strcpy(sentance1, sentance);

    printf("enter your second sentance:\n");
    fgets(sentance2, sizeof(sentance2), stdin);
    sentance2[strcspn(sentance2, "\n")] = '\0';

    printf("You entered:\n%s\n", strcat(sentance1, sentance2));
    return 0;
}