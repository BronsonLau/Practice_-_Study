// 3240. 最少翻转次数使二进制矩阵回文 II
// 给你一个 m x n 的二进制矩阵 grid 。

// 如果矩阵中一行或者一列从前往后与从后往前读是一样的，那么我们称这一行或者这一列是 回文 的。

// 你可以将 grid 中任意格子的值 翻转 ，也就是将格子里的值从 0 变成 1 ，或者从 1 变成 0 。

// 请你返回 最少 翻转次数，使得矩阵中 所有 行和列都是 回文的 ，且矩阵中 1 的数目可以被 4 整除 。

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = 0; i < m / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                int cnt1 = grid[i][j] + grid[i][n - 1 - j] +
                           grid[m - 1 - i][j] + grid[m - 1 - i][n - 1 - j];
                ans += min(cnt1, 4 - cnt1);
            }
        }

        int diff = 0, cnt1 = 0;
        if (m & 1) {
            for (int j = 0; j < n / 2; j++) {
                if (grid[m / 2][j] ^ grid[m / 2][n - 1 - j]) {
                    diff++;
                } else {
                    cnt1 += grid[m / 2][j] * 2;
                }
            }
        }
        if (n & 1) {
            for (int i = 0; i < m / 2; i++) {
                if (grid[i][n / 2] ^ grid[m - 1 - i][n / 2]) {
                    diff++;
                } else {
                    cnt1 += grid[i][n / 2] * 2;
                }
            }
        }
        if (m & 1 && n & 1) {
            ans += grid[m / 2][n / 2];
        }
        if (diff > 0) {
            ans += diff;
        } else {
            ans += cnt1 % 4;
        }
        return ans;
    }
};

// 答案
// 思路：分类讨论