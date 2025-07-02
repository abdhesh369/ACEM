#include<stdio.h>
void isPalindrome(int a, int b)
{
    for(int i = a; i <= b; i++)
    {
        int num = i, rem, rev = 0, original = i;
        while(num > 0) 
        {
            rem = num % 10;
            rev = rev * 10 + rem;
            num /= 10;
        }
        if(i == rev)
        {
            printf("%d ", i);
        }
    }
}

int main()
{
    int s, e;
    printf("Enter a starting & ending range:\n");
    scanf("%d %d", &s, &e);
    isPalindrome(s, e);
    return 0;
}