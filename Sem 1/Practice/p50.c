#include <stdio.h>
int main() {
    int x = 10;
    int *p=&x;   
    

    printf("Value of x = %d\n", x);
    printf("Address of x = %p\n", &x);
    printf("Pointer p stores = %p\n", p);
    printf("Value at address stored in p = %d\n", *p);

    return 0;
}
