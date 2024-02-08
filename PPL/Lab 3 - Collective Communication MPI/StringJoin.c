#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(int argc, char **argv)
{
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    char str1[100], str2[100];
    char recv_str1[100], recv_str2[100];
    char resultant[100][3];

    if (rank == 0)
    {

        printf("Enter 2 strings of same size : \n");
        gets(str1);
        gets(str2);

        printf("%s - %s\n", str1, str2);
    }
    char ch1, ch2;
    MPI_Scatter(str1, strlen(str1) / size, MPI_CHAR, &ch1, 1, MPI_CHAR, 0, MPI_COMM_WORLD);
    MPI_Scatter(str2, strlen(str2) / size, MPI_CHAR, &ch2, 1, MPI_CHAR, 0, MPI_COMM_WORLD);

    for (int i = 0; i < strlen(str1) / size; i++)
    {
        printf("p %d -> %c , %c\n", rank, ch1, ch2);
    }

    char res[3];
    res[0] = ch1;
    res[1] = ch2;
    res[2] = '\0';
    puts(res);

    MPI_Finalize();
}