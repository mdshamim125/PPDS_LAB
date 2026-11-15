// Problem 2: Parallel Matrix Addition
// Problem Statement
// Write a C program using OpenMP to add two 3×3 matrices.

#include <stdio.h>
#include <omp.h>

#define N 3

int main()
{
    int A[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[N][N] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int C[N][N];

    int i, j;

    // parallel: Creates multiple threads.
    // for: Distributes outer-loop iterations among threads.
    // private(j): Gives each thread its own independent copy of j.

    #pragma omp parallel for private(j)
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("Matrix Addition:\n");

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
