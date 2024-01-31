#include<mpi.h>
#include<stdio.h>
void main(int argc, char **argv)
{
    int rank,size;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    int num1=7,num2=3;

    switch(rank)
    {
        case 0:
        printf("%d - %d = %d\n",num1,num2,num1-num2);
        break;

        case 1:
        printf("%d + %d = %d\n",num1,num2,num1+num2);
        break;

        case 2:
        printf("%d * %d = %d\n",num1,num2,num1*num2);
        break;

        case 3:
        printf("%d / %d = %.2lf\n",num1,num2,(float)num1/num2);
        break;
    }

    MPI_Finalize();
}