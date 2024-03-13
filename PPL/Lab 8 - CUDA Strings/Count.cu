#include<stdio.h>
#include<string.h>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

__global__ void countOcc(char *str, char *word, int *count, int len_str, int len_word)
{
    int id=threadIdx.x;

    if(id<len_str-len_word+1)
    {
        int flag=1;
        for(int i=0;i<len_word;i++)
        {
            if(str[id+i]!=word[i])
            {
                flag=0;
                break;
            }
        }

        if(flag)
            atomicAdd(count,1);
    }
}

int main()
{
    int count;

    char str[]="foo la dee da da labs foo da la la foo la labs foo";
    char word[50];
    printf("String is : %s\n",str);
    printf("Enter word to count frequency : ");
    scanf("%s",word);

    int len_str=strlen(str);
    int len_word=strlen(word);

    char *d_word,*d_str;
    int *d_count;

    cudaMalloc((void**)&d_word,len_word*sizeof(char));
    cudaMalloc((void**)&d_str,len_str*sizeof(char));
    cudaMalloc((void**)&d_count,sizeof(int));

    cudaMemcpy(d_str,str,len_str*sizeof(char),cudaMemcpyHostToDevice);
    cudaMemcpy(d_word,word,len_word*sizeof(char),cudaMemcpyHostToDevice);

    countOcc<<<1,len_str>>>(d_str,d_word,d_count,len_str,len_word);

    cudaMemcpy(&count,d_count,sizeof(int),cudaMemcpyDeviceToHost);
    printf("Number of occurances : %d\n",count);

    return 1;
}