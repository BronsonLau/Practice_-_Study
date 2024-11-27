// 3250. 单调数组对的数目 I
// 困难
// 给你一个长度为 n 的 正 整数数组 nums 。

// 如果两个 非负 整数数组 (arr1, arr2) 满足以下条件，我们称它们是 单调 数组对：

// 两个数组的长度都是 n 。
// arr1 是单调 非递减 的，换句话说 arr1[0] <= arr1[1] <= ... <= arr1[n - 1] 。
// arr2 是单调 非递增 的，换句话说 arr2[0] >= arr2[1] >= ... >= arr2[n - 1] 。
// 对于所有的 0 <= i <= n - 1 都有 arr1[i] + arr2[i] == nums[i] 。
// 请你返回所有 单调 数组对的数目。

// 由于答案可能很大，请你将它对 109 + 7 取余 后返回。

class Solution {
public:
    int countOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(51, 0));
        int mod = 1e9 + 7;

        for (int v = 0; v <= nums[0]; ++v) {
            dp[0][v] = 1;
        }

        for (int i = 1; i < n; ++i) {
            for (int v2 = 0; v2 <= nums[i]; ++v2) {
                for (int v1 = 0; v1 <= v2; ++v1) {
                    if (nums[i - 1] - v1 >= nums[i] - v2 && nums[i] - v2 >= 0) {
                        dp[i][v2] = (dp[i][v2] + dp[i - 1][v1]) % mod;
                    }
                }
            }
        }

        int res = 0;
        for (int v : dp[n - 1]) {
            res = (res + v) % mod;
        }
        return res;
    }
};

// 朴素的动态规划
// 思路：
// 用 dp[i][v] 表示前 i 个数中，arr1 的最后一个数为 v 的方案数。
// 状态转移方程为：
// dp[i][v2] = sum(dp[i - 1][v1])，其中 v1 <= v2，nums[i - 1] - v1 >= nums[i] - v2，nums[i] - v2 >= 0。
// 最终答案为 sum(dp[n - 1])。

// 时间复杂度分析：O(n * 50 * 50) = O(nm^2)。
// 空间复杂度分析：O(n * 50) = O(nm)。
// 其中 n 是数组的长度，m 是数组的最大值。