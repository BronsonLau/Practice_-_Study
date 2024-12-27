// 3046. 分割数组
// 简单

// 给你一个长度为 偶数 的整数数组 nums 。你需要将这个数组分割成 nums1 和 nums2 两部分，要求：

// nums1.length == nums2.length == nums.length / 2 。
// nums1 应包含 互不相同 的元素。
// nums2也应包含 互不相同 的元素。
// 如果能够分割数组就返回 true ，否则返回 false 。

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            if (++count[num] > 2) {
                return false;
            }
        }
        return true;
    }
};

// 方法一：哈希表
// 思路与算法

// 用哈希表统计每个元素的出现次数，如果出现次数大于两次，则不能分割数组。
// 如果没有出现两次以上的元素，则可以分割数组。


// 复杂度分析
// 时间复杂度：O(n)，其中 n 是数组的长度。
// 空间复杂度：O(n)，其中 n 是数组的长度。