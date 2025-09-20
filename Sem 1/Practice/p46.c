#include <stdio.h>
#include <string.h>
int main()
{
    char sentance[99];
    int count = 1;
    printf("enter your sentance:\n");
    fgets(sentance, sizeof(sentance), stdin);
    sentance[strcspn(sentance, "\n")] = '\0';
    int len = strlen(sentance);
    for (int i = 0; i < len / 2; i++)
    {
        if (sentance[i] == sentance[len - 1 - i])
        {
            count = 0;
        }
    }

    if (!count)
    {
        printf("it is palindrome");
    }
    else
    {
        printf("it is not palindrome");
    }

    return 0;
}