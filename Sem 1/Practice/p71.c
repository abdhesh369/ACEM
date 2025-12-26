#include <stdio.h>
#include <conio.h>
int main()
{
    int num1, num2;
    char ch;
    // clrscr();
    printf("enter number: ");
    scanf("%d%d", &num1, &num2);
    printf("enter operator:\n");
    scanf(" %c", &ch);
    switch (ch)
    {
    case '+':
        printf("the sum is %d", num1 + num2);

        break;

    case '-':
        printf("the difference is %d", num1 - num2);

        break;

    case '*':
        printf("the multiply is %d", num1 * num2);

        break;

    case '/':
        printf("the division is %f", (float)num1 / num2);

        break;
    default:
        printf("invalid operator");
    }
    getch();
    return 0;
}