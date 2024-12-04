#include <stdio.h>

int main() {
    char name[50];
    int age;
    float height;
    char grade;

    // Input section
    printf("Enter your name: ");
    scanf("%49s", name); // Limit input to avoid buffer overflow

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your height in meters (e.g., 1.75): ");
    scanf("%f", &height);

    printf("Enter your grade (A/B/C/D/F): ");
    scanf(" %c", &grade); // Notice the space before %c to consume any leftover newline

    // Output section
    printf("\n--- User Information ---\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Height: %.2f meters\n", height);
    printf("Grade: %c\n", grade);

    return 0;
}
