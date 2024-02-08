#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
void main(int argc, char **argv)
{
    int rank, size, m, arraySize;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int n = size;
    int *nums;
    double avg_arr[n];

    if (rank == 0)
    {
        printf("Enter M value : ");
        scanf("%d", &m);
        arraySize = n * m;

        nums = (int *)malloc(arraySize * sizeof(int));

        for (int i = 0; i < arraySize; i++)
        {
            printf("Enter number %d/%d: ", i + 1, arraySize);
            scanf("%d", &nums[i]);
        }
    }
    MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);

    int *recv = (int *)malloc(m * sizeof(int));
    MPI_Scatter(nums, m, MPI_INT, recv, m, MPI_INT, 0, MPI_COMM_WORLD);

    double sum = 0, avg;
    for (int i = 0; i < m; i++)
        sum += recv[i];
    avg = sum / m;

    MPI_Gather(&avg, 1, MPI_DOUBLE, avg_arr, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        double avg_avg = 0;
        sum = 0;
        for (int i = 0; i < n; i++)
            sum += avg_arr[i];
        avg_avg = sum / n;

        printf("Average = %.3lf", avg_avg);
    }
    MPI_Finalize();
}