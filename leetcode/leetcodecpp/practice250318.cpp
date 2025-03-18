// 2614. 对角线上的质数
// 给你一个下标从 0 开始的二维整数数组 nums 。
// 返回位于 nums 至少一条 对角线 上的最大 质数 。如果任一对角线上均不存在质数，返回 0 。

// 注意：
// 如果某个整数大于 1 ，且不存在除 1 和自身之外的正整数因子，则认为该整数是一个质数。
// 如果存在整数 i ，使得 nums[i][i] = val 或者 nums[i][nums.length - i - 1]= val ，则认为整数 val 位于 nums 的一条对角线上。

// 简单模拟
class Solution {
    public:
        int diagonalPrime(vector<vector<int>>& nums) {
            int n = nums.size(), res = 0;
            for (int i = 0; i < n; i++) {
                if (isPrime(nums[i][i])) {
                    res = max(res, nums[i][i]);
                }
                if (isPrime(nums[i][n - i - 1])) {
                    res = max(res, nums[i][n - i - 1]);
                }
            }
            return res;
        }
    
        bool isPrime(int num) {
            if (num == 1) {
                return false;
            }
            int factor = 2;
            while (factor * factor <= num) {
                if (num % factor == 0) {
                    return false;
                }
                factor++;
            }
            return true;
        }
    };
    

// 时间复杂度：O(n * m^(1/2))，其中 n 是数组 nums 的长度。我们需要遍历数组 nums 一次。
// 空间复杂度：O(1)。