// 3240. 最少翻转次数使二进制矩阵回文 II
// 给你一个 m x n 的二进制矩阵 grid 。

// 如果矩阵中一行或者一列从前往后与从后往前读是一样的，那么我们称这一行或者这一列是 回文 的。

// 你可以将 grid 中任意格子的值 翻转 ，也就是将格子里的值从 0 变成 1 ，或者从 1 变成 0 。

// 请你返回 最少 翻转次数，使得矩阵中 所有 行和列都是 回文的 ，且矩阵中 1 的数目可以被 4 整除 。

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> f(4, INT_MAX / 2);
        f[0] = 0;
        for (int i = 0; i < (m + 1) / 2; i++) {
            for (int j = 0; j < (n + 1) / 2; j++) {
                int ones = grid[i][j], cnt = 1;
                if (j != n - 1 - j) {
                    ones += grid[i][n - 1 - j];
                    cnt++;
                }
                if (i != m - 1 - i) {
                    ones += grid[m - 1 - i][j];
                    cnt++;
                }
                if (i != m - 1 - i && j != n - 1 - j) {
                    ones += grid[m - 1 - i][n - 1 - j];
                    cnt++;
                }
                // 将这一组全部变成 1 的代价
                int cnt1 = cnt - ones;
                // 将这一组全部变成 0 的代价
                int cnt0 = ones;
                vector<int> tmp(4);
                for (int k = 0; k < 4; k++) {
                    tmp[k] = f[k] + cnt0;
                }
                for (int k = 0; k < 4; k++) {
                    tmp[(k + cnt) % 4] = min(tmp[(k + cnt) % 4], f[k] + cnt1);
                }
                swap(f, tmp);
            }
        }
        return f[0];
    }
};

// 答案
// 方法二：动态规划