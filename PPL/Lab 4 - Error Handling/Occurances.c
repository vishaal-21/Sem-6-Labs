#include <mpi.h>
#include <stdio.h>
int calcOcc(int arr[], int ele)
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        printf("arr %d ele %d\n", arr[i], ele);
        if (arr[i] == ele)
            count++;
    }

    printf("count  is %d\n", count);

    return count;
}
void main(int argc, char **argv)
{
    int rank, size, ele, total;
    int err;
    int arr[3][3];
    int subarr[3];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {
        printf("Enter 9 numbers : ");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }
        printf("Enter element to be searched : ");
        scanf("%d", &ele);
    }

    err=MPI_Bcast(&ele, 1, MPI_INT, 0, MPI_COMM_WORLD);
    if(err!=MPI_SUCCESS)
    {
        printf("MPI Broadcast failoed with error code %d");
        MPI_Abort(MPI_COMM_WORLD,1);
    }
    
    MPI_Scatter(arr, 3, MPI_INT, subarr, 3, MPI_INT, 0, MPI_COMM_WORLD);

    int occ = calcOcc(subarr, ele);

    err=MPI_Reduce(&occ, &total, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if(err!=MPI_SUCCESS)
    {
        char error_string[MPI_MAX_ERROR_STRING];
        int len;

        MPI_Error_string(err,error_string,&len);
        printf("MPI Scan failed with error code %d : %s",err,error_string);
        MPI_Abort(MPI_COMM_WORLD,1);
    }

    if (rank == 0)
        printf("Total occurances of %d = %d\n", ele, total);

    MPI_Finalize();
}