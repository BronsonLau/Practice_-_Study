// 3248. 矩阵中的蛇
// 大小为 n x n 的矩阵 grid 中有一条蛇。蛇可以朝 四个可能的方向 移动。矩阵中的每个单元格都使用位置进行标识： grid[i][j] = (i * n) + j。

// 蛇从单元格 0 开始，并遵循一系列命令移动。

// 给你一个整数 n 表示 grid 的大小，另给你一个字符串数组 commands，其中包括 "UP"、"RIGHT"、"DOWN" 和 "LEFT"。题目测评数据保证蛇在整个移动过程中将始终位于 grid 边界内。

// 返回执行 commands 后蛇所停留的最终单元格的位置。
class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int ans = 0;
        for (const string& c: commands) {
            if (c[0] == 'U') {
                ans -= n;
            }
            else if (c[0] == 'D') {
                ans += n;
            }
            else if (c[0] == 'L') {
                --ans;
            }
            else {
                ++ans;
            }
        }
        return ans;
    }
};

// 方法：模拟
// 步骤：
// 1. 初始化一个变量 ans，表示蛇的位置。
// 2. 遍历所有命令，对于每个命令，更新 ans 的值。
// 3. 返回最终的 ans 值。
// 时间复杂度：O(q)，其中 q 是命令的数量。
// 空间复杂度：O(1)。

// 提示：
// 1 <= n <= 1000
// 1 <= commands.length <= 1000
// commands[i] 由 "U"、"D"、"L" 和 "R" 组成
// 蛇在整个移动过程中将始终位于 grid 边界内
// 0 <= commands[i].length <= 50
// 0 <= i <= n * n - 1
// 0 <= n * n <= 10^6

