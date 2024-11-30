// 51. N 皇后
// 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。

// n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        auto solutions = vector<vector<string>>();
        auto queens = vector<int>(n, -1);
        solve(solutions, queens, n, 0, 0, 0, 0);
        return solutions;
    }

    void solve(vector<vector<string>> &solutions, vector<int> &queens, int n, int row, int columns, int diagonals1, int diagonals2) {
        if (row == n) {
            auto board = generateBoard(queens, n);
            solutions.push_back(board);
        } else {
            int availablePositions = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
            while (availablePositions != 0) {
                int position = availablePositions & (-availablePositions);
                availablePositions = availablePositions & (availablePositions - 1);
                int column = __builtin_ctz(position);
                queens[row] = column;
                solve(solutions, queens, n, row + 1, columns | position, (diagonals1 | position) >> 1, (diagonals2 | position) << 1);
                queens[row] = -1;
            }
        }
    }

    vector<string> generateBoard(vector<int> &queens, int n) {
        auto board = vector<string>();
        for (int i = 0; i < n; i++) {
            string row = string(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};


// 思路：
// 回溯
// 用一个整数 queens[i] 表示第 i 行皇后所在的列。
// 用一个整数 columns 表示哪些列已经有皇后。
// 用一个整数 diagonals1 表示哪些主对角线上已经有皇后。
// 皇后的位置，可以通过一个长度为 2n - 1 的数组来表示，其中数组的索引表示斜线编号，数组的值表示斜线方向。
// 斜线编号：从左上到右下的对角线编号从 0 开始，从左下到右上的对角线编号从 1 开始，依次类推。
// 斜线方向：0 表示没有皇后，1 表示有皇后。
// 用一个整数 diagonals2 表示哪些副对角线上已经有皇后。
// 时间复杂度分析：O(n!)。
// 空间复杂度分析：O(n)。

// 小结
// 回顾这道题，拿到这道题的时候，其实我们很容易看出需要使用枚举的方法来求解这个问题，当我们不知道用什么办法来枚举是最优的时候，可以从下面三个方向考虑：

// 子集枚举：可以把问题转化成「从 n 
// 2
//   个格子中选一个子集，使得子集中恰好有 n 个格子，且任意选出两个都不在同行、同列或者同对角线」，这里枚举的规模是 2 
// n 
// 2
 
//  ；
// 组合枚举：可以把问题转化成「从 n 
// 2
//   个格子中选择 n 个，且任意选出两个都不在同行、同列或者同对角线」，这里的枚举规模是 ( 
// n
// n 
// 2
 
// ​
//  )；
// 排列枚举：因为这里每行只能放置一个皇后，而所有行中皇后的列号正好构成一个 1 到 n 的排列，所以我们可以把问题转化为一个排列枚举，规模是 n!。
// 带入一些 n 进这三种方法验证，就可以知道哪种方法的枚举规模是最小的，这里我们发现第三种方法的枚举规模最小。这道题给出的两个方法其实和排列枚举的本质是类似的。

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/n-queens/solutions/398929/nhuang-hou-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。