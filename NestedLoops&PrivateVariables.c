// Problem 3: Parallel Matrix Multiplication
// Problem Statement
// Write a C program using OpenMP to multiply two 2×2 matrices.

#include <stdio.h>
#include <omp.h>

#define N 2

int main()
{
    int A[N][N] = {
        {1, 2},
        {3, 4}
    };

    int B[N][N] = {
        {5, 6},
        {7, 8}
    };

    int C[N][N] = {0};

    int i, j, k;

    #pragma omp parallel for private(j, k)
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            C[i][j] = 0;

            for(k = 0; k < N; k++)
            {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    printf("Matrix Multiplication:\n");

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%d ", C[i][j]);
        }

        printf("\n");
    }

    return 0;
}


// There are three loops:
// - i: Selects the row of matrix A.
// - j: Selects the column of matrix B.
// - k: Performs multiplication and addition.


// #pragma omp parallel for private(j, k)

// This distributes the outer loop (i) among threads.
// - i is automatically private because it is the loop iteration variable.
// - j is private because each thread needs its own inner-loop variable.
// - k is private because each thread needs its own multiplication-loop variable.
