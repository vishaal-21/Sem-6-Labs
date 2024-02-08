#include <cl/math_functions.h>
__kernel void convert(__global int *arr, __global int *res)
{
    int i = get_global_id(0);
    int num = arr[i];
    int index = 0;

    int revOctal[50], octal = 0, dig;
    while (num > 0)
    {
        dig = num % 8;
        revOctal[index++] = dig;
        num /= 8;
    }
    revOctal[index] = '\0';

    for (int j = 0; j < strlen(revOctal); j++)
    {
        octal = octal + (revOctal[j] * (10, j));
    }

    res[i] = octal;
}