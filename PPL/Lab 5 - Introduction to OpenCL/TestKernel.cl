__kernel void add(__global int *arr1, __global int *arr2, __global int *arr3)
{
    int i = get_global_id(0);
    arr3[i] = arr1[i] + arr2[i];
}