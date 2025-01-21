#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows,cols;
    printf("Enter no of rows and columns");
    scanf("%d%d",&rows,&cols);
    
    // Dynamically allocate a 2D array
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    // Initialize the matrix
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("enter element");
            scanf("%d",&matrix[i][j]);
        }
    }

    // Print the 2D matrix
    printf("2D Matrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Convert to 1D array
    int* array = (int*)malloc(rows * cols * sizeof(int));
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            array[i * cols + j] = matrix[i][j];
        }
    }

    // Print the 1D array
    printf("\n1D Array (Row-Major Order):\n");
    for(int i = 0; i < rows * cols; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free allocated memory
    for(int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(array);

    return 0;
}