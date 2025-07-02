#include <stdio.h>
int main()
// void main()
{
    int r;
    float area, PI = 3.14, cir;
    printf("enter the radius\n");
    scanf("%d", &r);
    area = PI * r * r;
    cir = 2 * PI * r;
    printf("area=%f \n cir=%f\n", area, cir);
    // getch();
    return 0;
}