// 90. 子集 II

// 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的 
// 子集
// （幂集）。

// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); ++mask) {
            t.clear();
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    if (i > 0 && (mask >> (i - 1) & 1) == 0 && nums[i] == nums[i - 1]) {
                        flag = false;
                        break;
                    }
                    t.push_back(nums[i]);
                }
            }
            if (flag) {
                ans.push_back(t);
            }
        }
        return ans;
    }
};

// 方法一：迭代法实现子集枚举
// 思路

// 考虑数组 [1,2,2]，选择前两个数，或者第一、三个数，都会得到相同的子集。
// 也就是说，对于当前选择的数 x，若前面有与其相同的数 y，且没有选择 y，此时包含 x 的子集，必然会出现在包含 y 的所有子集中。
// 我们可以通过判断这种情况，来避免生成重复的子集。代码实现时，可以先将数组排序；迭代时，若发现没有选择上一个数，且当前数字与上一个数相同，则可以跳过当前生成的子集。

// 复杂度分析
// 时间复杂度：O(n×2^n)，其中 n 是数组 nums 的长度。排序的时间复杂度为 O(nlogn)。
// 空间复杂度：O(n)。即构造子集使用的临时数组 t 的空间代价。

