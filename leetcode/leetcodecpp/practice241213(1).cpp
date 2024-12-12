// 3264. K 次乘运算后的最终数组 I
// 简单

// 给你一个整数数组 nums ，一个整数 k  和一个整数 multiplier 。

// 你需要对 nums 执行 k 次操作，每次操作中：

// 找到 nums 中的 最小 值 x ，如果存在多个最小值，选择最 前面 的一个。
// 将 x 替换为 x * multiplier 。
// 请你返回执行完 k 次乘运算之后，最终的 nums 数组。

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while (k--) {
            auto iter = min_element(nums.begin(), nums.end());
            *iter *= multiplier;
        }
        return nums;
    }
};

// 方法一：模拟
// 根据题意，对 nums 进行模拟操作，每次操作先找到 nums 的最前面的最小值，然后将该元素替换成乘以 multiplier 后的值，最后返回 k 次模拟操作后的数组 nums。

// 复杂度分析
// 时间复杂度：O(nk)，其中 n 是数组 nums 的长度，k 是操作次数。
// 空间复杂度：O(1)。返回值不计入空间复杂度。