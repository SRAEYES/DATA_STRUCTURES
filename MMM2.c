#include<stdio.h>

int main(){
    int a[10][10], b[10][10], product[10][10], sum = 0;
    int a_rows, a_columns, b_rows, b_columns;
    int i, j, k;

    // Input the dimensions of matrix A
    printf("Enter the number of rows and columns of matrix A: ");
    scanf("%d %d", &a_rows, &a_columns);

    // Input elements of matrix A
    printf("Enter elements of matrix A:\n");
    for(i = 0; i < a_rows; i++){
        for(j = 0; j < a_columns; j++){
            //printf("A[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // Input the dimensions of matrix B
    printf("Enter the number of rows and columns of matrix B: ");
    scanf("%d %d", &b_rows, &b_columns);

    // Check if matrix multiplication is possible
    if(b_rows != a_columns){
        printf("Sorry, matrix multiplication is not possible.\n");
        return 0;
    }

    // Input elements of matrix B
    printf("Enter elements of matrix B:\n");
    for(i = 0; i < b_rows; i++){
        for(j = 0; j < b_columns; j++){
           // printf("B[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    // Matrix multiplication
    for(i = 0; i < a_rows; i++){
        for(j = 0; j < b_columns; j++){
            sum = 0;
            for(k = 0; k < a_columns; k++){
                sum += a[i][k] * b[k][j];
            }
            product[i][j] = sum;
        }
    }

    // Print the resulting product matrix
    printf("Product of the matrices:\n");
    for(i = 0; i < a_rows; i++){
        for(j = 0; j < b_columns; j++){
            printf("%d\t", product[i][j]);
        }
        printf("\n");
    }

    return 0;
}
