#include<mpi.h>
#include<stdio.h>
#include<ctype.h>
void main(int argc, char **argv)
{
    int rank,size;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    char string[10]="ViSHal";

    if(islower(string[rank]))
        printf("%c",toupper(string[rank]));
    else
        printf("%c",tolower(string[rank]));

    MPI_Finalize();
}