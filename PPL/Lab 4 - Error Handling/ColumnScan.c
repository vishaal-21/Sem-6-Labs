#include <mpi.h>
#include <stdio.h>
void main(int argc, char **argv)
{
    int rank, size;
    int arr[4][4];
    int subarr[4];
    int partial[4];
    int res[4][4];
    char error_string[MPI_MAX_ERROR_STRING];
    int err;
    int len;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {
        printf("Enter 16 numbers : ");
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                printf("%d\t", arr[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    MPI_Scatter(arr, 4, MPI_INT, subarr, 4, MPI_INT, 0, MPI_COMM_WORLD);

    err = MPI_Scan(subarr, partial, 4, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    if (err != MPI_SUCCESS)
    {
        MPI_Error_string(err, error_string, &len);
        printf("MPI Scan failed with error code %d : %s", err, error_string);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    err = MPI_Gather(partial, 4, MPI_INT, arr, 4, MPI_INT, 0, MPI_COMM_WORLD);
    if (err != MPI_SUCCESS)
    {
        MPI_Error_string(err, error_string, &len);
        printf("MPI Gather failed with error code %d : %s", err, error_string);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    if (rank == 0)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                printf("%d\t", arr[i][j]);
            }
            printf("\n");
        }
    }

    MPI_Finalize();
}