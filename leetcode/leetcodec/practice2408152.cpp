// 方法二：动态规划（更加快捷的编译方法）

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int function2(int** grid , int gridSize , int* gridColSize)
{
    int m = gridSize; int n =  gridColSize[0];
    int precol[n];
    for (int i = 0; i < n; i++)
    {
        precol[i] = INT_MIN;

    }
    
    int answer = INT_MIN;

    for (int i = 0; i < m; i++)
    {
        int prerow = INT_MIN;
        for (int j = 0; j<n; j++)
        {
            int f = INT_MIN;
            if (i >0)
            {
                f = fmax(f , grid[i][j] + precol[j]);
            }
            if (j > 0)
            {
                f = fmax(f , grid[i][j] + prerow);
            }

            answer = fmax(answer , f);
            precol[j] = fmax(precol[j] , fmax(f,0) - grid[i][j]);
            prerow = fmax(prerow , fmax(f,0) - grid[i][j]);
        }
    }

    return answer;
}