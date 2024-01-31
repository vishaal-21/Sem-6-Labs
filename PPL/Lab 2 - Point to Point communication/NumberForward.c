#include<stdio.h>
#include"mpi.h"
void main(int argc,char **argv)
{
    int rank,size;
    int num;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Status status;

    if(rank==0)
    {
        printf("Enter a number : ");
        scanf("%d",&num);

        fprintf(stdout,"Rank %d : %d\n",rank,num);
        num++;
        MPI_Send(&num,1,MPI_INT,1,1,MPI_COMM_WORLD);
        fflush(stdout);

        MPI_Recv(&num,1,MPI_INT,size-1,1,MPI_COMM_WORLD,&status);
        printf("Rank 0 receives again %d\n",num);
    }
    else
    {   
        MPI_Recv(&num,1,MPI_INT,rank-1,1,MPI_COMM_WORLD,&status);
        fprintf(stdout,"Rank %d : %d\n",rank,num);
        fflush(stdout);
        num++;

        if(rank==size-1)
            MPI_Send(&num,1,MPI_INT,0,1,MPI_COMM_WORLD);
        else
            MPI_Send(&num,1,MPI_INT,rank+1,1,MPI_COMM_WORLD);
    }
    MPI_Finalize();
}