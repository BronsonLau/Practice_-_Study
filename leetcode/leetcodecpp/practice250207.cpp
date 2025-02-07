// 59. 螺旋矩阵 II
// 中等

// 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            int maxNum = n * n;
            int curNum = 1;
            vector<vector<int>> matrix(n, vector<int>(n));
            int row = 0, column = 0;
            vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // 右下左上
            int directionIndex = 0;
            while (curNum <= maxNum) {
                matrix[row][column] = curNum;
                curNum++;
                int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
                if (nextRow < 0 || nextRow >= n || nextColumn < 0 || nextColumn >= n || matrix[nextRow][nextColumn] != 0) {
                    directionIndex = (directionIndex + 1) % 4;  // 顺时针旋转至下一个方向
                }
                row = row + directions[directionIndex][0];
                column = column + directions[directionIndex][1];
            }
            return matrix;
        }
    };
    
    

    // 方法一：模拟
// 复杂度分析
// 时间复杂度：O(n^2)，其中 n 是给定的正整数。矩阵的大小是 n×n，需要填入矩阵中的每个元素。
// 空间复杂度：O(1)。除了返回的矩阵以外，空间复杂度是常数。

