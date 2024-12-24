// 3218. 切蛋糕的最小总开销 I
// 中等

// 有一个 m x n 大小的矩形蛋糕，需要切成 1 x 1 的小块。

// 给你整数 m ，n 和两个数组：

// horizontalCut 的大小为 m - 1 ，其中 horizontalCut[i] 表示沿着水平线 i 切蛋糕的开销。
// verticalCut 的大小为 n - 1 ，其中 verticalCut[j] 表示沿着垂直线 j 切蛋糕的开销。
// 一次操作中，你可以选择任意不是 1 x 1 大小的矩形蛋糕并执行以下操作之一：

// 沿着水平线 i 切开蛋糕，开销为 horizontalCut[i] 。
// 沿着垂直线 j 切开蛋糕，开销为 verticalCut[j] 。
// 每次操作后，这块蛋糕都被切成两个独立的小蛋糕。

// 每次操作的开销都为最开始对应切割线的开销，并且不会改变。

// 请你返回将蛋糕全部切成 1 x 1 的蛋糕块的 最小 总开销。

class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        vector<int> cache(m * m * n * n, -1);
        auto index = [&](int row1, int col1, int row2, int col2) -> int {
            return (row1 * n + col1) * m * n + row2 * n + col2;
        };
        function<int(int, int, int, int)> dp;
        dp = [&](int row1, int col1, int row2, int col2) -> int {
            if (row1 == row2 && col1 == col2) {
                return 0;
            }
            int ind = index(row1, col1, row2, col2);
            if (cache[ind] >= 0) {
                return cache[ind];
            }
            cache[ind] = INT_MAX;
            for (int i = row1; i < row2; i++) {
                cache[ind] = min(cache[ind], dp(row1, col1, i, col2) + dp(i + 1, col1, row2, col2) + horizontalCut[i]);
            }
            for (int i = col1; i < col2; i++) {
                cache[ind] = min(cache[ind], dp(row1, col1, row2, i) + dp(row1, i + 1, row2, col2) + verticalCut[i]);
            }
            return cache[ind];
        };
        return dp(0, 0, m - 1, n - 1);
    }
};

// 方法一：记忆化搜索
// 思路

// 将原问题分解成子问题，设计函数 dp[row 
// 1
// ​
//  ,col 
// 1
// ​
//  ,row 
// 2
// ​
//  ,col 
// 2
// ​
//  ] 表示切割完整的子矩形至最小单元的代价，其中子矩形的两个对角顶点的坐标分别为 (row 
// 1
// ​
//  ,col 
// 1
// ​
//  ) 和 (row 
// 2
// ​
//  ,col 
// 2
// ​
//  )。我们可以任意水平或者垂直切一刀，然后将问题分解成更小的子问题，直到分到最小单元。遍历所有可能的切法，取出最小值作为子问题的返回值。因为递归过程中有许多重复状态，我们利用记忆话搜索的方式来降低时间复杂度。最后返回 dp(0,0,m−1,n−1) 即可。


// 时间复杂度：O(m 
// 2
//  ×n 
// 2
//  ×(m+n))，一共有 O(m 
// 2
//  ×n 
// 2
//  ) 个状态，每个状态消耗 O(m+n) 的时间计算。

// 空间复杂度：O(m 
// 2
//  ×n 
// 2
//  )。

