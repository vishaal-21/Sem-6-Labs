#include<stdio.h>
#include<mpi.h>
void main(int argc, char **argv)
{
    int rank,size;
    int num;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Status status;

    if(rank==0)
    {
        printf("Enter number : ");
        scanf("%d",&num);
        MPI_Send(&num,1,MPI_INT,1,1,MPI_COMM_WORLD);
        fprintf(stdout,"Number %d sent\n",num);
        fflush(stdout);
    }
    else
    {
        MPI_Recv(&num,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
        fprintf(stdout,"Number %d received\n",num);
        fflush(stdout);
    }

    MPI_Finalize();
}