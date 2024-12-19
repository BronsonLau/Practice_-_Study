// 3285. 找到稳定山的下标
// 简单

// 有 n 座山排成一列，每座山都有一个高度。给你一个整数数组 height ，其中 height[i] 表示第 i 座山的高度，再给你一个整数 threshold 。

// 对于下标不为 0 的一座山，如果它左侧相邻的山的高度 严格大于 threshold ，那么我们称它是 稳定 的。我们定义下标为 0 的山 不是 稳定的。

// 请你返回一个数组，包含所有 稳定 山的下标，你可以以 任意 顺序返回下标数组。

class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        vector<int> result;
        for (int i = 1; i < height.size(); i++) {
            if (height[i - 1] > threshold) {
                result.push_back(i);
            }
        }
        return result;
    }
};

// 过于简单题
// 时间复杂度分析：O(n)
// 空间复杂度分析：O(n)
