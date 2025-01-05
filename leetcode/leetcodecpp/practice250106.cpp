// 2274. 不含特殊楼层的最大连续楼层数
// 中等

// Alice 管理着一家公司，并租用大楼的部分楼层作为办公空间。Alice 决定将一些楼层作为 特殊楼层 ，仅用于放松。

// 给你两个整数 bottom 和 top ，表示 Alice 租用了从 bottom 到 top（含 bottom 和 top 在内）的所有楼层。另给你一个整数数组 special ，其中 special[i] 表示  Alice 指定用于放松的特殊楼层。

// 返回不含特殊楼层的 最大 连续楼层数。

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        special.push_back(bottom - 1);
        special.push_back(top + 1);
        sort(special.begin(), special.end());

        int n = special.size();
        int ans = 0;
        for (int i = 0; i < n - 1; ++i) {
            ans = max(ans, special[i + 1] - special[i] - 1);
        }
        return ans;
    }
};

// 方法一：排序
// 思路与算法:
// 如果我们将给定的数组 special 按照升序排序，那么相邻两个元素之间的楼层就都不是特殊楼层。如果相邻的两个元素分别为 x,y，那么非特殊楼层的数量即为 y−x−1。
// 但这样会忽略最开始和结束的非特殊楼层，因此我们可以在排序前将 bottom−1 和 top+1 也放入数组中，一起进行排序。这样一来，所有 y−x−1 中的最大值即为答案。


// 复杂度分析
// 时间复杂度：O(nlogn)，其中 n 是数组 special 的长度。
// 空间复杂度：O(logn)，即为排序需要使用的栈空间。