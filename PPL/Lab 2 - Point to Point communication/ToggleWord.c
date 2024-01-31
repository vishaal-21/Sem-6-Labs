#include<stdio.h>
#include"mpi.h"
#include<ctype.h>
#include<string.h>
void main(int argc,char **argv)
{
    int rank;

    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Status status;

    if(rank==0)
    {
        char str[50];
        printf("Enter a word : ");
        gets(str);
        MPI_Ssend(str,strlen(str),MPI_CHAR,1,1,MPI_COMM_WORLD);
        MPI_Recv(str,50,MPI_CHAR,1,1,MPI_COMM_WORLD,&status);

        fprintf(stdout,"String received back : %s",str);
        fflush(stdout);
    }
    else
    {
        char recv_str[50];
        MPI_Recv(recv_str,50,MPI_CHAR,0,1,MPI_COMM_WORLD,&status);

        for(int i=0;i<strlen(recv_str);i++)
        {
            if(islower(recv_str[i]))
                recv_str[i]=toupper(recv_str[i]);
            else if(isupper(recv_str[i]))
                recv_str[i]=tolower(recv_str[i]);
        }
        MPI_Ssend(recv_str,strlen(recv_str),MPI_CHAR,0,1,MPI_COMM_WORLD);
    }
    MPI_Finalize();
}