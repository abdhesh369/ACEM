#include <stdio.h>
#include <unistd.h>  // For sleep function

void printHeart() {
    printf("  **   **  \n");
    printf(" *  * *  * \n");
    printf("*    *    *\n");
    printf(" *       * \n");
    printf("  *     *  \n");
    printf("   *   *   \n");
    printf("    * *    \n");
    printf("     *     \n");
}

void proposeLove() {
    printf("\n\n");
    printf("Loading your proposal...\n");
    sleep(2);
    printf("\n");
    
    // Printing heart
    printHeart();
    printf("\n");

    // Displaying message with a delay
    sleep(1);
    printf("I ❤️ You!\n");
    sleep(1);
    printf("Will you be mine? ❤️\n\n");
}

int main() {
    proposeLove();
    return 0;
}
