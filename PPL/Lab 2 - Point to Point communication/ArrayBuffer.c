#include<stdio.h>
#include"mpi.h"
void main(int argc,char **argv)
{
    int rank,size;
    int num;
    int buffer[50];

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Status status;
    MPI_Buffer_attach(buffer,sizeof(buffer));

    if(rank==0)
    {
        for(int i=0;i<size-1;i++)
        {
            printf("Enter a number : ");
            scanf("%d",&buffer[i]);
        }   

        for(int i=0;i<size-1;i++)
            MPI_Bsend(&buffer[i],1,MPI_INT,i+1,1,MPI_COMM_WORLD);
    }
    else
    {
        MPI_Recv(&num,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);

        fprintf(stdout,"Rank %d : %d\n",rank,num);
        fflush(stdout);

        if(rank%2==0)
            num=num*num;
        else
            num=num*num*num;

        fprintf(stdout,"Rank %d : %d\n",rank,num);
        fflush(stdout);
    }

    MPI_Buffer_detach(&buffer,&size);
    MPI_Finalize();
}