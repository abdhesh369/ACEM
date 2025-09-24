#include <stdio.h>
int main()
{
    float centigrade, fahrenheit;
    printf("Enter the temperature in centigrade:\n");
    scanf("%f", &centigrade);
    fahrenheit = (centigrade * 9 / 5) + 32;
    printf("The temperature in fahrenheit is: %0.2f", fahrenheit);
    return 0;
}