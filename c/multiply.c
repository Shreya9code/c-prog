#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to initialize the matrix with random floating point values between 0 and 1.0
void initialize_matrix(float **matrix, int N)
 {
    for (int i = 0; i < N; i++)
     {
        for (int j = 0; j < N; j++)
         {
            matrix[i][j] = (float)rand()/RAND_MAX ;
        }
    }
}

// Function to multiply two matrices
void multiply_matrices(float **matrixOne, float **matrixTwo, float **resultMatrix, int N) {
    for (int i = 0; i < N; i++)
     {
        for (int j = 0; j < N; j++) 
        {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < N; k++)
             {
                resultMatrix[i][j] += matrixOne[i][k] * matrixTwo[k][j];
            }
            //printf("%f",resultMatrix);
            //return resultMatrix[i][j];
        }
    }
}

// Function to print the matrix
void print_matrix(float **matrix, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%0.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    int N;
    printf("Enter the value of N: ");
    scanf("%d", &N);

    // Dynamically allocate memory for the matrices
    float **matrixOne = (float **)malloc(N * sizeof(float *));
    float **matrixTwo = (float **)malloc(N * sizeof(float *));
    float **resultMatrix = (float **)malloc(N * sizeof(float *));
    for (int i = 0; i < N; i++)
     {
        matrixOne[i] = (float *)malloc(N * sizeof(float));
        matrixTwo[i] = (float *)malloc(N * sizeof(float));
        resultMatrix[i] = (float *)malloc(N * sizeof(float));
    }

    // Initialize the matrices with random values
    srand(time(NULL));
    initialize_matrix(matrixOne, N);
    initialize_matrix(matrixTwo, N);

    // Measure the time taken for matrix multiplication
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    multiply_matrices(matrixOne, matrixTwo, resultMatrix, N);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken to multiply two %d x %d matrices: %f seconds\n", N, N, cpu_time_used);

    printf("Matrix1\n");
    print_matrix(matrixOne,N);

    printf("Matrix1\n");
    print_matrix(matrixTwo,N);

    printf("Matrix1\n");
    print_matrix(resultMatrix,N);

    // Free allocated memory
    for (int i = 0; i < N; i++) {
        free(matrixOne[i]);
        free(matrixTwo[i]);
        free(resultMatrix[i]);
    }
    free(matrixOne);
    free(matrixTwo);
    free(resultMatrix);

    return 0;
}