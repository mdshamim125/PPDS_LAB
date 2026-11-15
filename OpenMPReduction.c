// Problem 6: Parallel Sum, Maximum, Minimum and Average Using Reduction

#include <stdio.h>
#include <omp.h>

int main()
{
    int A[8] = {10, 20, 30, 40, 50, 60, 70, 80};

    int i;
    int sum = 0;
    int max = A[0];
    int min = A[0];

    double average;

    /* Sum */
    #pragma omp parallel for reduction(+:sum)
    for(i = 0; i < 8; i++)
    {
        sum = sum + A[i];
    }

    /* Maximum */
    #pragma omp parallel for reduction(max:max)
    for(i = 0; i < 8; i++)
    {
        if(A[i] > max)
        {
            max = A[i];
        }
    }

    /* Minimum */
    #pragma omp parallel for reduction(min:min)
    for(i = 0; i < 8; i++)
    {
        if(A[i] < min)
        {
            min = A[i];
        }
    }

    /* Average */
    average = (double)sum / 8;

    printf("Sum     = %d\n", sum);
    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);
    printf("Average = %.2f\n", average);

    return 0;
}