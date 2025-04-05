// 1863. 找出所有子集的异或总和再求和

// 一个数组的 异或总和 定义为数组中所有元素按位 XOR 的结果；如果数组为 空 ，则异或总和为 0 。
// 例如，数组 [2,5,6] 的 异或总和 为 2 XOR 5 XOR 6 = 1 。

// 给你一个数组 nums ，请你求出 nums 中每个 子集 的 异或总和 ，计算并返回这些值相加之 和 。
// 注意：在本题中，元素 相同 的不同子集应 多次 计数。

// 数组 a 是数组 b 的一个 子集 的前提条件是：从 b 删除几个（也可能不删除）元素能够得到 a 。


// 解法1：DFS + 求与运算 + 求和
class Solution {
    public:
        int res;
        int n;
        
        void dfs(int val, int idx, vector<int>& nums){
            if (idx == n){
                // 终止递归
                res += val;
                return;
            }
            // 考虑选择当前数字
            dfs(val ^ nums[idx], idx + 1, nums);
            // 考虑不选择当前数字
            dfs(val, idx + 1, nums);
        }
        
        int subsetXORSum(vector<int>& nums) {
            res = 0;
            n = nums.size();
            dfs(0, 0, nums);
            return res;
        }
    };
    
// 时间复杂度：O(2^n)，其中 n 是数组 nums 的长度。
// 空间复杂度：O(n)，用于递归栈的空间开销。


// 解法2：数学（二项式展开） + 位运算
class Solution {
    public:
        int subsetXORSum(vector<int>& nums) {
            int res = 0;
            int n = nums.size();
            for (auto num: nums){
                res |= num;
            }
            return res << (n - 1);
        }
    };
    
// 时间复杂度：O(n)
// 空间复杂度：O(1)，只使用了常数级别的额外空间。
// 其中 n 是数组 nums 的长度。    