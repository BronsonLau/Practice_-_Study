2873. 有序三元组中的最大值 I
给你一个下标从 0 开始的整数数组 nums 。
请你从所有满足 i < j < k 的下标三元组 (i, j, k) 中，找出并返回下标三元组的最大值。如果所有满足条件的三元组的值都是负数，则返回 0 。
下标三元组 (i, j, k) 的值等于 (nums[i] - nums[j]) * nums[k] 。


// 贪心算法的简单实践
class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            long long res = 0, imax = 0, dmax = 0;
            for (int k = 2; k < n; k++){
                imax = max(imax, (long long)nums[k - 2]);
                dmax = max(dmax, imax - nums[k - 1]);
                res = max(res, dmax * nums[k]);
            }
            return res;
        }
    };


// 时间复杂度：O(n)，其中 n 是数组 nums 的长度。
// 空间复杂度：O(1)。