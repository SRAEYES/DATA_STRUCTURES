#include <stdio.h>

int main() {
    int arr[20], num, n;

    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);

    printf("\nEnter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the number that has to be searched: ");
    scanf("%d", &num);

    // Search for the number in the array using if-else
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            printf("\n%d is found in the array at position: %d\n", num, i + 1);
            break;
        } else if (i == n - 1) {  // Only print if it's the last element and not found
            printf("\n%d does not exist in the array\n", num);
        }
    }

    return 0;
}
