#include <stdio.h>
int main()
{
    char name[20];
    printf("enter your name:\n");
    fgets(name, sizeof(name), stdin);
    printf("You entered:\n%s", name);
    return 0;
}