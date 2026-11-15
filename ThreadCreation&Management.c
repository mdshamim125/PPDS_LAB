// Problem 4: Hello World Using Multiple Threads
// Problem Statement
// Write a C program using OpenMP to create multiple threads and print a Hello message from each thread.

#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        int total = omp_get_num_threads();

        printf("Hello from Thread %d of %d\n", id, total);
    }

    return 0;
}



omp_get_thread_num() returns the ID of the currently executing thread.
omp_get_num_threads() returns the total number of threads in the current parallel team.
