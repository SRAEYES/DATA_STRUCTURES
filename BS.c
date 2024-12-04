#include <stdio.h>

#define SIZE 10

void selection_sort(int arr[], int n);
int binary_search(int arr[], int n, int num);

int main() {
    int arr[SIZE], num, n;

    printf("\nEnter the number of elements in the array: ");
    scanf("%d", &n);

    printf("\nEnter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array
    selection_sort(arr, n);

    // Display the sorted array
    printf("\nThe sorted array is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    // Input the number to search
    printf("\nEnter the number that has to be searched: ");
    scanf("%d", &num);

    // Perform binary search
    int position = binary_search(arr, n, num);

    // Output the result
    if (position != -1) {
        printf("\n%d is present in the array at position %d\n", num, position + 1);
    } else {
        printf("\n%d does not exist in the array\n", num);
    }

    return 0;
}

// Function to perform selection sort
void selection_sort(int arr[], int n) {
    int i, j, min_index, temp;
    for (i = 0; i < n-1; i++) {
        min_index = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

// Function to perform binary search
int binary_search(int arr[], int n, int num) {
    int beg = 0, end = n - 1, mid;

    while (beg <= end) {
        mid = (beg + end) / 2;

        if (arr[mid] == num) {
            return mid;  // Return the position where the number is found
        } else if (arr[mid] > num) {
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }

    return -1;  // Return -1 if the number is not found
}
