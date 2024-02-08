#include <stdio.h>
#include "mpi.h"
#include <stdlib.h>
#include <string.h>
int nonVowelCount(char str[50])
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' str[i]!=' '))
            count++;
    }
    return count;
}
void main(int argc, char **argv)
{
    int rank, size, m;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    int n = size;

    char str[100];
    int answer[100];

    if (rank == 0)
    {
        printf("Enter string of length multiple of %d: ", size);
        gets(str);
        m = strlen(str) / n;
    }

    char recv_str[100];
    MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);

    MPI_Scatter(str, m, MPI_CHAR, recv_str, m, MPI_CHAR, 0, MPI_COMM_WORLD);
    recv_str[m] = '\0';

    int nonVow;
    nonVow = nonVowelCount(recv_str);

    MPI_Gather(&nonVow, 1, MPI_INT, answer, 1, MPI_INT, 0, MPI_COMM_WORLD);
    answer[n] = '\0';

    if (rank == 0)
    {
        int sum = 0;
        for (int i = 0; i < size; i++)
            sum += answer[i];

        printf("Number of non-vowels = %d\n", sum);
    }

    MPI_Finalize();
}