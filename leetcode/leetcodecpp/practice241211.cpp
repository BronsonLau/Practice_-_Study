// 2717. 半有序排列
// 简单

// 给你一个下标从 0 开始、长度为 n 的整数排列 nums 。

// 如果排列的第一个数字等于 1 且最后一个数字等于 n ，则称其为 半有序排列 。你可以执行多次下述操作，直到将 nums 变成一个 半有序排列 ：

// 选择 nums 中相邻的两个元素，然后交换它们。
// 返回使 nums 变成 半有序排列 所需的最小操作次数。

// 排列 是一个长度为 n 的整数序列，其中包含从 1 到 n 的每个数字恰好一次。

class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        auto [first, last] = minmax_element(nums.begin(), nums.end());
        return first + nums.size() - 1 - last - (last < first);
    }
};

// 方法一：模拟
// 思路与算法

// 根据题意我们找到 1 在数组中的索引 first，n 在数组中的索引 last，此时分为两种情况讨论：

// 如果 first<last，此时将 1 通过交换相邻元素移到数组的首位需要的交换次数为 first，将 n 通过交换相邻元素移到数组的末尾需要的交换次数为 n−1−last，总的交换次数即为 first+n−1−last；

// 如果 first>last，此时将 1 通过交换相邻元素移到数组的首位需要的交换次数为 first，将 n 通过交换相邻元素移到数组的末尾需要的交换次数为 n−1−first，由于 first>last，实际交换过程时 1 与 n 会同时交换 1 次，因此会减少 1 次交换，总的交换次数即为 first+n−1−last−1。

// 时间复杂度：O(n)，其中 n 是数组的长度。需要遍历数组两次。
// 空间复杂度：O(1)。只需要常数的额外空间。

// 注意：简单题目的思路应当从分类讨论出发，不要认为是全排序的问题