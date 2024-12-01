// 52. N 皇后 II
// n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。

// 给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。

class Solution {
public:
    int totalNQueens(int n) {
        return solve(n, 0, 0, 0, 0);
    }

    int solve(int n, int row, int columns, int diagonals1, int diagonals2) {
        if (row == n) {
            return 1;
        } else {
            int count = 0;
            int availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
            while (availablePositions != 0) {
                int position = availablePositions & (-availablePositions);
                availablePositions = availablePositions & (availablePositions - 1);
                count += solve(n, row + 1, columns | position, (diagonals1 | position) << 1, (diagonals2 | position) >> 1);
            }
            return count;
        }
    }
};

// 思路：
// 回溯
// 用一个整数 columns 表示哪些列已经有皇后。
// 用一个整数 diagonals1 表示哪些主对角线上已经有皇后。
// 用一个整数 diagonals2 表示哪些副对角线上已经有皇后。
// 时间复杂度分析：O(n!)。
// 空间复杂度分析：O(n)。
// 递归调用的深度为 n，因此空间复杂度为 O(n)。
// 递归调用的次数为 n，因此时间复杂度为 O(n!)。
