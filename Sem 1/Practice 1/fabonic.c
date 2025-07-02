#include <stdio.h>

int main() {
    int n, a = 0, b = 1;

    printf("Enter the number of terms: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }

    if (n <= 0) {
        printf("Fibonacci Series: %d\n", a);
    } else if (n == 1) {
        printf("Fibonacci Series: %d\n", a);
    } else {
        printf("Fibonacci Series: %d, %d", a, b);

        for (int i = 2; i < n; ++i) {
            int next = a + b;
            a = b;
            b = next;
            printf(", %d", next);
        }
        printf("\n");
    }

    return 0;
}
