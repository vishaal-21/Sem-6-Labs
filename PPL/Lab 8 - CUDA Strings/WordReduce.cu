#include<stdio.h>
#include<string.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void operate(char *word, char *res, int len, int res_len)
{
    int id=threadIdx.x;
    int temp=len;
    int index=id;

    for(int i=0;i<len;i++)
    {
        if(index<res_len)
        {
            res[index]=word[id];
        }
        index+=temp;
        temp--;
    }
}

int main()
{
    char word[50];
    printf("Enter a word : ");
    scanf("%s",word);

    int len=strlen(word);
    int res_len=(len*(len+1))/2;

    char res[res_len];

    char *d_word,*d_res;

    cudaMalloc((void**)&d_word,len*sizeof(char));
    cudaMalloc((void**)&d_res,res_len*sizeof(char));

    cudaMemcpy(d_word,word,len*sizeof(char),cudaMemcpyHostToDevice);

    operate<<<1,len>>>(d_word,d_res,len,res_len);

    cudaMemcpy(res,d_res,res_len*sizeof(char),cudaMemcpyDeviceToHost);
    res[res_len]='\0';

    printf("Result : %s\n",res);

    return 1;
}