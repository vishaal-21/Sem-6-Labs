#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
void main(int argc, char **argv)
{
    int rank, size, m, arraySize;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int *nums;

    if (rank == 0)
    {
        printf("Enter M value : ");
        scanf("%d", &m);
        arraySize = size * m;

        nums = (int *)malloc(arraySize * sizeof(int));

        for (int i = 0; i < arraySize; i++)
        {
            printf("Enter number : ");
            scanf("%d", &nums[i]);
        }
    }
    MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("%d -> %d\n", rank, m);

    int *recv = (int *)malloc(m * sizeof(int));
    MPI_Scatter(nums, m, MPI_INT, recv, m, MPI_INT, 0, MPI_COMM_WORLD);

    for (int i = 0; i < m; i++)
    {
        printf("p %d -> %d \n", rank, recv[i]);
    }

    free(nums);
    free(recv);
    MPI_Finalize();
}