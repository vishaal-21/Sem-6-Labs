#include<mpi.h>
#include<stdio.h>
void main(int argc, char** argv)
{
    int rank,size,fact=1,result;
    int err;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    for(int i=1;i<=rank+1;i++)
        fact*=i;

    err=MPI_Scan(&fact, &result, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    if(err!=MPI_SUCCESS)
    {
        // char error_string[MPI_MAX_ERROR_STRING];
        // int len;

        // MPI_Error_string(err,error_string,&len);
        printf("MPI Scan failed with error code %d : %s",err,error_string);
        MPI_Abort(MPI_COMM_WORLD,1);
    }

    printf("Process %d: Local value = %d, Global sum = %d\n", rank+1, fact, result);

    MPI_Finalize();
}