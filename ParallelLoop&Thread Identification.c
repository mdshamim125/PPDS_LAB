// Problem 5: Parallel Array Addition with Thread Identification
// Problem Statement
// Write a C program using OpenMP to add two arrays, each containing 8 elements.


#include <stdio.h>
#include <omp.h>

int main()
{
    int A[8], B[8], C[8];
    int i;

    for(i = 0; i < 8; i++)
    {
        B[i] = i + 1;
        C[i] = 10;
    }

    #pragma omp parallel for
    for(i = 0; i < 8; i++)
    {
        A[i] = B[i] + C[i];

        printf("Thread %d calculates A[%d]\n",
               omp_get_thread_num(), i);
        // omp_get_thread_num()
        // This function identifies which thread is calculating a particular array element.
    }

    printf("\nResult:\n");

    for(i = 0; i < 8; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}


