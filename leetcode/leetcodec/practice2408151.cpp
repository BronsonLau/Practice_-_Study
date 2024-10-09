// 题目3148 矩阵中的最大得分——给你一个由 正整数 组成、大小为 m x n 的矩阵 grid。
// 你可以从矩阵中的任一单元格移动到另一个位于正下方或正右侧的任意单元格（不必相邻）。
// 从值为 c1 的单元格移动到值为 c2 的单元格的得分为 c2 - c1 。

// 你可以从 任一 单元格开始，并且必须至少移动一次。

// 返回你能得到的 最大 总得分

// 思路：动态规划（步骤清晰版本）。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int function1(int** grid , int gridSize ,int* gridColSize){
    int m = gridSize; int n = gridColSize[0];
    int prerow[m][n]; int precol[m][n];
    int f[m][n]; int answer = INT_MIN;

    for (int i = 0;i < m;i++)  // 初始化
    {
        for(int j = 0;j < n;j++)
        {
            prerow[i][j] = 0;
            precol[i][j] = 0;
            f[i][j] = INT_MIN;
        }

        
    }

    for (int i = 0 ;i < m; i++) 
    {
        for (int j = 0;j < n; j++)
        {
            if (i > 0)
            {
                f[i][j] = fmax(f[i][j] , grid[i][j] + precol[i-1][j]);

            }

            if (j > 0)
            {
                f[i][j] = fmax(f[i][j] , grid[i][j] + prerow[i][j-1]);

            }

            answer = fmax(answer , f[i][j]);

            prerow[i][j] = precol[i][j] = fmax(f[i][j] , 0 ) - grid[i][j];

            if (i > 0)
            {
                precol[i][j] = fmax(precol[i][j] , precol[i-1][j]);

            }

            if (j > 0)
            {
                prerow[i][j] = fmax(prerow[i][j] , prerow[i][j-1]);

            }

        }

        return answer;
    }
}