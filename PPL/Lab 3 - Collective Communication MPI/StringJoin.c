#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(int argc, char **argv)
{
    int rank, size, m;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    char str1[100], str2[100];
    char recv_str1[100], recv_str2[100];
    char *res;

    int n = size;

    if (rank == 0)
    {
        printf("Enter 2 strings of same size multiple of %d : \n", size);
        gets(str1);
        gets(str2);
        int len1 = strlen(str1);
        int len2 = strlen(str2);
        res = (char *)malloc((2*len1) * sizeof(char));

        if (len1 != len2)
        {
            printf("Strings have unequal length");
            return;
        }

        m = len1 / n;
    }

    MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(str1, m, MPI_CHAR, recv_str1, m, MPI_CHAR, 0, MPI_COMM_WORLD);
    MPI_Scatter(str2, m, MPI_CHAR, recv_str2, m, MPI_CHAR, 0, MPI_COMM_WORLD);
    recv_str1[m] = '\0';
    recv_str2[m] = '\0';

    // for (int i = 0; i < m; i++)
    // {
    //     printf("p %d -> %c\n", rank, recv_str1[i]);
    // }

    // for (int i = 0; i < m; i++)
    // {
    //     printf("p %d -> %c\n", rank, recv_str2[i]);
    // }

    char partial[2 * m];
    int index = 0;
    for (int i = 0; i < 2 * m; i++)
    {
        partial[index++] = recv_str1[i];
        partial[index++] = recv_str2[i];
    }

    MPI_Gather(partial, 2 * m, MPI_CHAR, res, 2 * m, MPI_CHAR, 0, MPI_COMM_WORLD);

    if (rank == 0)
        printf("Final string = %s", res);

    MPI_Finalize();
}