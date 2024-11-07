// 3254. 长度为 K 的子数组的能量值 I

// 给你一个长度为 n 的整数数组 nums 和一个正整数 k 。

// 一个数组的 能量值 定义为：

// 如果 所有 元素都是依次 连续 且 上升 的，那么能量值为 最大 的元素。
// 否则为 -1 。
// 你需要求出 nums 中所有长度为 k 的 
// 子数组
//  的能量值。

// 请你返回一个长度为 n - k + 1 的整数数组 results ，其中 results[i] 是子数组 nums[i..(i + k - 1)] 的能量值。

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        int cnt = 0;
        vector<int> ans(n - k + 1, -1);
        for (int i = 0; i < n; i++) {
            cnt = i == 0 || nums[i] - nums[i - 1] != 1 ? 1 : cnt + 1;
            if (cnt >= k) {
                ans[i - k + 1] = nums[i];
            }
        }
        return ans;
    }
};


// 统计长度法 只需要遍历一次数组 时间复杂度为O(n)
// 对于原数组极大情况，只能用这个方法