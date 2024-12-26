// 3159. 查询数组中元素的出现位置
// 中等

// 给你一个整数数组 nums ，一个整数数组 queries 和一个整数 x 。

// 对于每个查询 queries[i] ，你需要找到 nums 中第 queries[i] 个 x 的位置，并返回它的下标。如果数组中 x 的出现次数少于 queries[i] ，该查询的答案为 -1 。

// 请你返回一个整数数组 answer ，包含所有查询的答案。

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) {
                indices.emplace_back(i);
            }
        }
        vector<int> res;
        for (int q : queries) {
            if (indices.size() < q) {
                res.emplace_back(-1);
            } else {
                res.emplace_back(indices[q - 1]);
            }
        }
        return res;
    }
};

// 方法一：统计下标
// 思路与算法

// 用数组 indices 记录 nums 中所有等于 x 的下标 i，此时给定的查询 queries[i]，如果 queries[i] 大于 indices 的长度，则查询答案为 −1，否则答案为 indices[queries[i]−1]，返回查询结果即可。


// 复杂度分析
// 时间复杂度：O(n+q)，其中 n 表示给定数组 nums 的长度， q 表示给定的查询数组 queries 的长度。只需遍历数组 nums 与 queries 一次即可。
// 空间复杂度：O(n)，其中 n 表示给定数组 nums 的长度。记录 x 出现的小标，需要的空间最多为 O(n)。

