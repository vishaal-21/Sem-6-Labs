#include <stdio.h>
#include <CL/cl.h>
#define MAX_SIZE 0x100000
void main()
{
    int *arr1 = (int *)malloc(5 * sizeof(int));
    int *arr2 = (int *)malloc(5 * sizeof(int));

    printf("Enter 5 numbers : ");
    for (int i = 0; i < 5; i++)
        scanf("%d", &arr1[i]);

    printf("Enter 5 more numbers : ");
    for (int i = 0; i < 5; i++)
        scanf("%d", &arr2[i]);

    // LOAD KERNEL CODE TO STRING ARRAY
    FILE *fp = fopen("TestKernel.cl", "r");
    char *source = (char *)malloc(MAX_SIZE);
    fread(source, 1, MAX_SIZE, fp);
    fclose(fp);

    // CREATE A PLATFORM
    cl_platform_id platform;
    clGetPlatformIDs(1, &platform, NULL);

    // GET AVAILABLE DEVICES
    cl_device_id device;
    clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &device, NULL);

    // CREATE A CONTEXT
    cl_context context = clCreateContext(NULL, 1, &device, NULL, NULL, NULL);

    // CREATE COMMAND QUEUE
    cl_command_queue commandQueue = clCreateCommandQueue(context, device, NULL, NULL);

    // CREATE MEMORY BUFFERS ON THE DEVICE FOR EACH OF THE INPUTS
    cl_mem obj_a = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(int) * 5, NULL, NULL);
    cl_mem obj_b = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(int) * 5, NULL, NULL);
    cl_mem obj_c = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(int) * 5, NULL, NULL);

    // COPY ARRAYS TO RESPECTIVE BUFFERS
    clEnqueueWriteBuffer(commandQueue, obj_a, CL_TRUE, 0, sizeof(int) * 5, arr1, 0, NULL, NULL);
    clEnqueueWriteBuffer(commandQueue, obj_b, CL_TRUE, 0, sizeof(int) * 5, arr2, 0, NULL, NULL);

    // CREATE PROGRAM FROM KERNEL SOURCE
    cl_program program = clCreateProgramWithSource(context, 1, (const char **)&source, NULL, NULL);

    // BUILD PROGRAM
    clBuildProgram(program, 1, &device, NULL, NULL, NULL);

    // CREATE KERNEL OBJECT
    cl_kernel kernel = clCreateKernel(program, "add", NULL);

    // SET KERNEL ARGUMENTS
    clSetKernelArg(kernel, 0, sizeof(cl_mem), (void *)&obj_a);
    clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&obj_b);
    clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&obj_c);

    // EXECUTE KERNEL ON THE ARRAY
    size_t global_size = 5;
    size_t local_size = 1;

    // EXECUTE KERNEL
    cl_event event;
    clEnqueueNDRangeKernel(commandQueue, kernel, 1, NULL, &global_size, &local_size, 0, NULL, NULL);
    clFinish(commandQueue);

    // READ RESULTANT MEMORY BUFFER
    int *res = (int *)malloc(sizeof(int) * 5);
    clEnqueueReadBuffer(commandQueue, obj_c, CL_TRUE, 0, sizeof(int) * 5, res, 0, NULL, NULL);

    // DISPLAY
    for (int i = 0; i < 5; i++)
        printf("%d ", res[i]);

    // CLEAN UP
    clFlush(commandQueue);
    clReleaseKernel(kernel);
    clReleaseProgram(program);
    clReleaseMemObject(obj_a);
    clReleaseMemObject(obj_b);
    clReleaseMemObject(obj_c);
    clReleaseCommandQueue(commandQueue);
    clReleaseContext(context);

    free(arr1);
    free(arr2);
    free(res);
}