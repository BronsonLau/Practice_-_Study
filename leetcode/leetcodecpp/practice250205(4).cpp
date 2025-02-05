// 78. 子集

// 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的
// 子集（幂集）。

// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    void dfs(int cur, vector<int>& nums) {
        if (cur == nums.size()) {
            ans.push_back(t);
            return;
        }
        t.push_back(nums[cur]);
        dfs(cur + 1, nums);
        t.pop_back();
        dfs(cur + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return ans;
    }
};


// 方法二：递归法实现子集枚举
// 思路与算法
// 我们也可以用递归来实现子集枚举。
// 假设我们需要找到一个长度为 n 的序列 a 的所有子序列，代码框架是这样的：

// vector<int> t;
// void dfs(int cur, int n) {
//     if (cur == n) {
//         // 记录答案
//         // ...
//         return;
//     }
//     // 考虑选择当前位置
//     t.push_back(cur);
//     dfs(cur + 1, n, k);
//     t.pop_back();
//     // 考虑不选择当前位置
//     dfs(cur + 1, n, k);
// }

// 上面的代码中，dfs(cur,n) 参数表示当前位置是 cur，原序列总长度为 n。原序列的每个位置在答案序列中的状态有被选中和不被选中两种，我们用 t 数组存放已经被选出的数字。在进入 dfs(cur,n) 之前 [0,cur−1] 位置的状态是确定的，而 [cur,n−1] 内位置的状态是不确定的，dfs(cur,n) 需要确定 cur 位置的状态，然后求解子问题 dfs(cur+1,n)。对于 cur 位置，我们需要考虑 a[cur] 取或者不取，如果取，我们需要把 a[cur] 放入一个临时的答案数组中（即上面代码中的 t），再执行 dfs(cur+1,n)，执行结束后需要对 t 进行回溯；如果不取，则直接执行 dfs(cur+1,n)。在整个递归调用的过程中，cur 是从小到大递增的，当 cur 增加到 n 的时候，记录答案并终止递归。可以看出二进制枚举的时间复杂度是 O(2 
// n
//  )。



// 复杂度分析
// 时间复杂度：O(n×2^n)。一共2^n个状态，每种状态需要 O(n) 的时间来构造子集。
// 空间复杂度：O(n)。临时数组 t 的空间代价是 O(n)，递归时栈空间的代价为 O(n)。

