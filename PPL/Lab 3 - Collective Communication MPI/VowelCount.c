#include <stdio.h>
#include "mpi.h"
#include <stdlib.h>
#include <string.h>
int nonVowelCount(char str[50])
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'))
            count++;
    }
    printf("%d\n", count);
    return count;
}
void main(int argc, char **argv)
{
    int rank, size, n;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    char str[100];
    char recv_str[100];
    int answer[size];

    if (rank == 0)
    {
        printf("Enter string of length multiple of %d: ", size);
        gets(str);
        n = strlen(str) / size;
    }
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
    MPI_Scatter(str, n, MPI_CHAR, recv_str, n, MPI_CHAR, 0, MPI_COMM_WORLD);

    int nonVow = nonVowelCount(recv_str);
    MPI_Gather(&nonVow, 1, MPI_INT, answer, size, MPI_INT, 0, MPI_COMM_WORLD);

    int sum = 0;
    if (rank == 0)
    {
        for (int i = 0; i < size; i++)
            sum += answer[i];

        printf("Number of non-vowels = %d\n", sum);
    }

    MPI_Finalize();
}