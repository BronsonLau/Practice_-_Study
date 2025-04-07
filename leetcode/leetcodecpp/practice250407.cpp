// 416. 分割等和子集

// 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

// NP完全问题，难以有多项式算法
// 动态规划法
// 时间复杂度：O(n*target)，其中 n 是输入数组的长度，target 是输入数组元素和的一半。
// 空间复杂度：O(target)，我们只需要一个一维数组来存储状态，因此空间复杂度为 O(target)。
class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            int n = nums.size();
            if (n < 2) return false;
            int sum = 0, maxNum = 0;
            for (auto& num : nums){
                sum += num;
                maxNum = max(maxNum, num);
            }
        
        if(sum & 1) {return false;}
        int target = sum / 2;
        if(maxNum > target) {return false;}
        vector<int> dp(target + 1, 0);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
                int num = nums[i];
                for (int j = target; j >= num; --j) {
                    dp[j] |= dp[j - num];
                }
            }
            return dp[target];
    }
    
    };

//     这道题可以换一种表述：给定一个只包含正整数的非空数组 nums[0]，判断是否可以从数组中选出一些数字，使得这些数字的和等于整个数组的元素和的一半。因此这个问题可以转换成「0−1 背包问题」。
//     这道题与传统的「0−1 背包问题」的区别在于，传统的「0−1 背包问题」要求选取的物品的重量之和不能超过背包的总容量，这道题则要求选取的数字的和恰好等于整个数组的元素和的一半。
//     类似于传统的「0−1 背包问题」，可以使用动态规划求解。
//     在使用动态规划求解之前，首先需要进行以下判断。

// 根据数组的长度 n 判断数组是否可以被划分。如果 n<2，则不可能将数组分割成元素和相等的两个子集，因此直接返回 false。

// 计算整个数组的元素和 sum 以及最大元素 maxNum。如果 sum 是奇数，则不可能将数组分割成元素和相等的两个子集，因此直接返回 false。如果 sum 是偶数，则令 target= sum /2 
// ​
//  ，需要判断是否可以从数组中选出一些数字，使得这些数字的和等于 target。如果 maxNum>target，则除了 maxNum 以外的所有元素之和一定小于 target，因此不可能将数组分割成元素和相等的两个子集，直接返回 false。

// (??)创建二维数组 dp，包含 n 行 target+1 列，其中 dp[i][j] 表示从数组的 [0,i] 下标范围内选取若干个正整数（可以是 0 个），是否存在一种选取方案使得被选取的正整数的和等于 j。初始时，dp 中的全部元素都是 false。

// 在定义状态之后，需要考虑边界情况。以下两种情况都属于边界情况。

// 如果不选取任何正整数，则被选取的正整数之和等于 0。因此对于所有 0≤i<n，都有 dp[i][0]=true。
// 当 i==0 时，只有一个正整数 nums[0] 可以被选取，因此 dp[0][nums[0]]=true。

// 对于 i>0 且 j>0 的情况，如何确定 dp[i][j] 的值？需要分别考虑以下两种情况。

// 如果 j≥nums[i]，则对于当前的数字 nums[i]，可以选取也可以不选取，两种情况只要有一个为 true，就有 dp[i][j]=true。
// 如果不选取 nums[i]，则 dp[i][j]=dp[i−1][j]；
// 如果选取 nums[i]，则 dp[i][j]=dp[i−1][j−nums[i]]。
// 如果 j<nums[i]，则在选取的数字的和等于 j 的情况下无法选取当前的数字 nums[i]，因此有 dp[i][j]=dp[i−1][j]。

// (??)且需要注意的是第二层的循环我们需要从大到小计算，因为如果我们从小到大更新 dp 值，那么在计算 dp[j] 值的时候，dp[j−nums[i]] 已经是被更新过的状态，不再是上一行的 dp 值。



    