#include <stdio.h>
#include <stdlib.h>

int main() {
    int **a, **b, **c;
    int a_r, a_c, b_r, b_c;
    int i, j, k;

    // Input for matrix one
    printf("\nEnter rows and columns for matrix one: ");
    scanf("%d%d", &a_r, &a_c);

    // Input0 for matrix two
    printf("\nEnter rows and columns for matrix two: ");
    scanf("%d%d", &b_r, &b_c);

    // Check if matrix multiplication is possible
    if (a_c != b_r) {
        printf("\nMatrix multiplication is not possible");
        return 0;
    }

    // Allocate memory for matrix one
    a = (int **)malloc(sizeof(int *) * a_r);
    for (i = 0; i < a_r; i++) {
        a[i] = (int *)malloc(sizeof(int) * a_c);
    }

    // Allocate memory for matrix two
    b = (int **)malloc(sizeof(int *) * b_r);
    for (i = 0; i < b_r; i++) {
        b[i] = (int *)malloc(sizeof(int) * b_c);
    }

    // Allocate memory for the product matrix
    c = (int **)malloc(sizeof(int *) * a_r);
    for (i = 0; i < a_r; i++) {
        c[i] = (int *)malloc(sizeof(int) * b_c);
    }

    // Input elements for matrix one
    printf("\nEnter elements for matrix one :\n", a_r, a_c);
    for (i = 0; i < a_r; i++) {
        for (j = 0; j < a_c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Input elements for matrix two
    printf("\nEnter elements for matrix two :\n", b_r, b_c);
    for (i = 0; i < b_r; i++) {
        for (j = 0; j < b_c; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Initialize the product matrix
    for (i = 0; i < a_r; i++) {
        for (j = 0; j < b_c; j++) {
            c[i][j] = 0;
        }
    }

    // Multiply matrix one and matrix two
    for (i = 0; i < a_r; i++) {
        for (j = 0; j < b_c; j++) {
            for (k = 0; k < a_c; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Display the result
    printf("\nProduct of matrix one and two is:\n");
    for (i = 0; i < a_r; i++) {
        for (j = 0; j < b_c; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (i = 0; i < a_r; i++) {
        free(a[i]);
        free(c[i]);
    }
    free(a);
    free(c);

    for (i = 0; i < b_r; i++) {
        free(b[i]);
    }
    free(b);
}
