#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char sentance[99];
    int count = 0;
    printf("enter your sentance:\n");
    fgets(sentance, sizeof(sentance), stdin);
    sentance[strcspn(sentance, "\n")] = '\0';
    for (int i = 0; i < strlen(sentance); i++)
    {
        char sh = tolower(sentance[i]);
        if (sh == 'a' || sh == 'e' || sh == 'i' || sh == 'o' || sh == 'u')
        {
            count++;
        }
    }

    printf("You entered:\n%s\n", sentance);
    printf("Your entered sentance has %d vowel letters\n", count);
    return 0;
}