#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count = 0;
int* temp;
int tempSize;

bool check(int mask ,int k,int n)
    {
        tempSize = 0;
        int sum = 0;
        for(int i=0; i<9; i++)
        {
            if((1<<i) & mask) // 检查mask中的第‘i'位是否是1（二进制按位）；
            {
                temp [ tempSize++ ] = i+1;
                sum += i+1;
            }
        }

        return tempSize == k && sum == n;
    }

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes) 
{
    *returnColumnSizes = (int*)malloc(sizeof(int)*100001);
    int **output = (int**)malloc(sizeof(int*)*100001);
    temp = (int*)malloc(sizeof(int)*100001);
    *returnSize = 0;

    for (int mask = 0; mask < (1<<9) ; ++mask)
    {
        if(check(mask , k , n))
        {
            int* tmp = (int*)malloc(sizeof(int)*tempSize);
            memcpy(tmp , temp , sizeof(int) * tempSize);
            output[*returnSize] = tmp;
            (*returnColumnSizes)[(*returnSize)++] = tempSize;
        }
    }

    return output;
}

