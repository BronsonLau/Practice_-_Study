// 2270. 分割数组的方案数
// 中等

// 给你一个下标从 0 开始长度为 n 的整数数组 nums 。
// 如果以下描述为真，那么 nums 在下标 i 处有一个 合法的分割 ：

// 前 i + 1 个元素的和 大于等于 剩下的 n - i - 1 个元素的和。
// 下标 i 的右边 至少有一个 元素，也就是说下标 i 满足 0 <= i < n - 1 。
// 请你返回 nums 中的 合法分割 方案数。

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long left = 0, right = accumulate(nums.begin(), nums.end(), 0LL);
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            left += nums[i];
            right -= nums[i];
            if (left >= right) {
                ++ans;
            }
        }
        return ans;
    }
};

// 方法一：枚举 + 前缀和
// 思路与算法:
// 我们只需要枚举所有的分割位置，并找出其中的合法分割即可。
// 具体地，我们用 left 和 right 分别表示分割左侧和右侧的所有元素之和。
// 初始时，left=0，right 的值为给定数组 nums 的所有元素之和。我们从小到大依次枚举每一个分割位置，当枚举到位置 i 时，我们将 left 加上 nums[i]，并将 right 减去 nums[i]，这样就可以实时正确地维护分割左侧和右侧的元素之和。
// 如果 left≥right，那么就找出了一个合法分割。

// 复杂度分析:
// 时间复杂度：O(n)。
// 空间复杂度：O(1)。