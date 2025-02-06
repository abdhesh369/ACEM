#include <stdio.h>
#include <conio.h>

int main() {
    float r, area, pi = 3.14;
    
    printf("Enter radius: ");
    scanf("%f", &r);

    area = pi * r * r;
    printf("Area of circle is %f\n", area);
    return 0;
}
