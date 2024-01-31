#include<mpi.h>
#include<stdio.h>
int reverse(int num)
{
    int rev=0;
    while(num>0)
    {
        rev=(rev*10) + num%10;
        num/=10;
    }

    return rev;
}
void main(int argc, char **argv)
{
    int rank,size;
    int numbers[10]={34,435,1236,456,234,14,734,86,614,34352};

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    int num=numbers[rank];
    int rev=reverse(num);
    printf("%d ",rev);

    MPI_Finalize();
}