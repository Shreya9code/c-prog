#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} Triplet;

void readMatrix(int rows, int cols, int **matrix) {
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void convertToTriplet(int rows, int cols, int **matrix, Triplet triplets[], int *size) {
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                triplets[k].row = i;
                triplets[k].col = j;
                triplets[k].value = matrix[i][j];
                k++;
            }
        }
    }
    *size = k;
}

void transposeTriplet(Triplet triplets[], int size, Triplet transposed[]) {
    for (int i = 0; i < size; i++) {
        transposed[i].row = triplets[i].col;
        transposed[i].col = triplets[i].row;
        transposed[i].value = triplets[i].value;
    }
}

void printTriplet(Triplet triplets[], int size) {
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", triplets[i].row, triplets[i].col, triplets[i].value);
    }
}

int main() {
    int rows, cols;
    
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);
    
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    
    readMatrix(rows, cols, matrix);

    Triplet *triplets = (Triplet *)malloc(rows * cols * sizeof(Triplet));
    int size;
    convertToTriplet(rows, cols, matrix, triplets, &size);

    printf("Sparse representation in Triplet format:\n");
    printTriplet(triplets, size);

    Triplet *transposed = (Triplet *)malloc(size * sizeof(Triplet));
    transposeTriplet(triplets, size, transposed);

    printf("Transposed sparse representation in Triplet format:\n");
    printTriplet(transposed, size);

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    free(triplets);
    free(transposed);

    return 0;
}