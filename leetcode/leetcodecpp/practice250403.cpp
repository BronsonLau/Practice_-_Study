// 2874. 有序三元组中的最大值 II
// 给你一个下标从 0 开始的整数数组 nums 。

// 请你从所有满足 i < j < k 的下标三元组 (i, j, k) 中，找出并返回下标三元组的最大值。如果所有满足条件的三元组的值都是负数，则返回 0 。

// 下标三元组 (i, j, k) 的值等于 (nums[i] - nums[j]) * nums[k] 。

// 3 <= nums.length <= 10^5
// 1 <= nums[i] <= 10^6

// 注意 题目与昨天相同 但数据量不同
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            vector<int> leftMax(n), rightMax(n);
            for (int i = 1; i < n; i++) {
                leftMax[i] = max(leftMax[i - 1], nums[i - 1]);
                rightMax[n - 1 - i] = max(rightMax[n - i], nums[n - i]);
            }
            long long res = 0;
            for (int j = 1; j < n - 1; j++) {
                res = max(res, (long long)(leftMax[j] - nums[j]) * rightMax[j]);
            }
            return res;
        }
    };
    
// 贪心 + 后缀和 算法
// 也可以用昨天的简单贪心

// 时间复杂度：O(n)，其中 n 是数组 nums 的长度。
// 空间复杂度：O(1)。    