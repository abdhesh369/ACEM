#include <stdio.h>
#include <string.h>
int main()
{
    char sentance[99];
    char sentance1[99];
    printf("enter your sentance:\n");
    fgets(sentance, sizeof(sentance), stdin);
    sentance[strcspn(sentance, "\n")] = '\0';
    for (int i = 0; i < strlen(sentance); i++)
    {

        if (sentance[i] == strrev(sentance[i]))
        {
            printf("it is pelindrome");
        }
        else
        {
            printf("it is not pelindrome");
        }
    }

    return 0;
}