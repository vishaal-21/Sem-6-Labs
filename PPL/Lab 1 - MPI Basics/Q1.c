#include<mpi.h>
#include<stdio.h>
#include<math.h>
void main(int argc, char **argv)
{
    int rank,size;

    int x=4;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    double res = pow(x,rank);
    printf("For process %d : %.2lf\n",rank,res);

    MPI_Finalize();
}