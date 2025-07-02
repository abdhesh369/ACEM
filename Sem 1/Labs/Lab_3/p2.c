#include<stdio.h>
#include<math.h>
int main()
{
    float a, b, c, x, y, real, img, q;
    printf("Enter the coefficient of a, b, c\n");
    scanf("%f %f %f", &a, &b, &c);
    q = b * b - 4 * a * c;
    if (q == 0)
    {
        x = y = -b / (2 * a);
        printf("roots are real and equal\n");
        printf("root 1 = root 2 = %f\n", x);
    }
    else if (q > 0)
    {
        x = (-b + sqrt(q)) / (2 * a);
        y = (-b - sqrt(q)) / (2 * a);
        printf("roots are real and distinct\n");
        printf("root 1 = %f\n", x);
        printf("root 2 = %f\n", y);
    }
    else
    {
        real = -b / (2 * a);
        img = sqrt(-q) / (2 * a);
        printf("roots are complex and imaginary\n");
        printf("root 1 = %f + %fi\n", real, img);
        printf("root 2 = %f - %fi\n", real, img);
    }

    return 0;
}