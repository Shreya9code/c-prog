#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} Triplet;

void readTriplet(Triplet triplets[], int size) {
    printf("Enter the row, column, and value for each non-zero element:\n");
    for (int i = 0; i < size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d %d %d", &triplets[i].row, &triplets[i].col, &triplets[i].value);
    }
}

void addSparseMatrices(Triplet A[], int sizeA, Triplet B[], int sizeB, Triplet result[], int *sizeResult) {
    int i = 0, j = 0, k = 0;

    while (i < sizeA && j < sizeB) {
        if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) {
            result[k++] = A[i++];
        } else if (B[j].row < A[i].row || (B[j].row == A[i].row && B[j].col < A[i].col)) {
            result[k++] = B[j++];
        } else {
            result[k] = A[i];
            result[k].value = A[i].value + B[j].value;
            if (result[k].value != 0) {
                k++;
            }
            i++;
            j++;
        }
    }

    while (i < sizeA) {
        result[k++] = A[i++];
    }

    while (j < sizeB) {
        result[k++] = B[j++];
    }

    *sizeResult = k;
}

void printTriplet(Triplet triplets[], int size) {
    printf("Row\tCol\tValue\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", triplets[i].row, triplets[i].col, triplets[i].value);
    }
}

int main() {
    int sizeA, sizeB;

    printf("Enter the number of non-zero elements in the first matrix: ");
    scanf("%d", &sizeA);
    Triplet *A = (Triplet *)malloc(sizeA * sizeof(Triplet));
    readTriplet(A, sizeA);

    printf("Enter the number of non-zero elements in the second matrix: ");
    scanf("%d", &sizeB);
    Triplet *B = (Triplet *)malloc(sizeB * sizeof(Triplet));
    readTriplet(B, sizeB);

    Triplet *result = (Triplet *)malloc((sizeA + sizeB) * sizeof(Triplet));
    int sizeResult;

    addSparseMatrices(A, sizeA, B, sizeB, result, &sizeResult);

    printf("Resultant sparse matrix after addition:\n");
    printTriplet(result, sizeResult);

    free(A);
    free(B);
    free(result);

    return 0;
}