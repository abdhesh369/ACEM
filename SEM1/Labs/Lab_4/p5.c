#include <stdio.h>

int main() {
    int num, max, min, choice;
    
    // Initial input
    printf("Enter a number: ");
    scanf("%d", &num);
    
    max = min = num; // Initialize max and min with the first number
    
    while (1) {
        printf("Do you want to enter another number? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;
        }
        
        printf("Enter a number: ");
        scanf("%d", &num);
        
        if (num > max) {
            max = num;
        }
        if (num < min) {
            min = num;
        }
    }
    
    printf("Maximum value: %d\n", max);
    printf("Minimum value: %d\n", min);
    
    return 0;
}
