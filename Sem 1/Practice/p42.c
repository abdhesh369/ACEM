#include <stdio.h>
#include<string.h>
int main()
{
    char name[20];
    printf("enter your name:\n");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name,"\n")]='\0';
    printf("You entered:\n%s", name);
    return 0;
}