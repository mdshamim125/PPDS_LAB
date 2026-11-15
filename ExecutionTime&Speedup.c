// Problem 1: Parallel Array Addition with Performance Measurement
// Problem Statement
// Write a C program using OpenMP to add two large arrays of 100 million elements.

#include <stdio.h>
#include <omp.h>

#define N 100000000

int main()
{
    static int A[N], B[N], C[N];

    int i;
    double start, end;
    double sequential_time, parallel_time;
    double speedup;

    /* Initialize arrays */
    for(i = 0; i < N; i++)
    {
        A[i] = i;
        B[i] = i * 2;
    }

    /* SEQUENTIAL */

    start = omp_get_wtime();

    for(i = 0; i < N; i++)
    {
        C[i] = A[i] + B[i];
    }

    end = omp_get_wtime();

    sequential_time = end - start;

    /* PARALLEL */

    start = omp_get_wtime();

    #pragma omp parallel for
    for(i = 0; i < N; i++)
    {
        C[i] = A[i] + B[i];
    }

    end = omp_get_wtime();

    parallel_time = end - start;

    /* SPEEDUP */

    speedup = sequential_time / parallel_time;

    printf("Sequential Time = %f seconds\n", sequential_time);
    printf("Parallel Time   = %f seconds\n", parallel_time);
    printf("Speedup         = %f\n", speedup);

    return 0;
}