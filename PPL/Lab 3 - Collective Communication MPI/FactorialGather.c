#include<mpi.h>
#include<stdio.h>
int fact(int n)
{
    int f=1;
    while(n>0)
    {
        f*=n;
        n--;
    }

    return f;
}
void main(int argc,char **argv)
{
    int rank,size,val,sum;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    int nums[size],factorial[size];

    if(rank==0)
    {
        for(int i=0;i<size;i++)
        {
            printf("Enter number : ");
            scanf("%d",&nums[i]);
        }
    }
    MPI_Scatter(nums,1,MPI_INT,&val,1,MPI_INT,0,MPI_COMM_WORLD);

    int fct=fact(val);
    printf("Factorial of %d in process %d = %d\n",val,rank,fct);

    MPI_Gather(&fct,1,MPI_INT,factorial,1,MPI_INT,0,MPI_COMM_WORLD);

    if(rank==0)
    {
        for(int i=0;i<size;i++)
        {
            sum+=factorial[i];
        }
        printf("Sum of all factorials = %d",sum);
    }
    MPI_Finalize();
}