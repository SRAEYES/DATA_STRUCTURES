#include <stdio.h>

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

int main() {
    int arr[20], num, n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: Sort the array
    selection_sort(arr, n);

    // Step 2: Display the sorted array
    printf("The sorted array is: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Step 3: Input the number to search
    printf("Enter the number that has to be searched: ");
    scanf("%d", &num);

    // Step 4: Perform binary search
    int position = binary_search(arr, n, num);

    // Step 5: Output the result
    if (position != -1) {
        printf("%d is present in the array at position %d\n", num, position + 1);
    } else {
        printf("%d does not exist in the array\n", num);
    }

    return 0;
}
