// 368. 最大整除子集
// 给你一个由 无重复 正整数组成的集合 nums ，请你找出并返回其中最大的整除子集 answer ，子集中每一元素对 (answer[i], answer[j]) 都应当满足：
// answer[i] % answer[j] == 0 ，或
// answer[j] % answer[i] == 0
// 如果存在多个有效解子集，返回其中任何一个均可。


// 动态规划
class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            int len  = nums.size();
            sort(nums.begin(), nums.end());
    
            vector<int> dp(len, 1);
            int maxSize = 1;
            int maxVal = dp[0];
    
            for(int i = 1; i < len; i++){
                for(int j = 0; j < i; j++){
                    if(nums[i] % nums[j] == 0){
                        dp[i] = max(dp[i], dp[j] + 1);
                    }
                }
    
                if(dp[i] > maxSize){
                    maxSize = dp[i];
                    maxVal = nums[i];
                }
            }
    
            vector<int> res;
            if(maxSize == 1){
                res.push_back(nums[0]);
                return res;
            }
    
            for(int i = len - 1; i>=0 && maxSize >= 0; i--){
                if(dp[i] == maxSize && maxVal % nums[i] == 0){
                    res.push_back(nums[i]);
                    maxVal = nums[i];
                    maxSize --;
                }
            }
            return res;
        }
    };

    // 前言
    // 首先需要理解什么叫「整除子集」。根据题目的描述，如果一个所有元素互不相同的集合中的任意元素存在整除关系，就称为整除子集。为了得到「最大整除子集」，我们需要考虑如何从一个小的整除子集扩充成为更大的整除子集。
    
    // 根据整除关系具有传递性，即如果 a 
    // ∣
    // ∣
    // ​
    //  b，并且 b 
    // ∣
    // ∣
    // ​
    //  c，那么 a 
    // ∣
    // ∣
    // ​
    //  c，可知：
    
    // 如果整数 a 是整除子集 S 
    // 1
    // ​
    //   的最小整数 b 的约数（即 a 
    // ∣
    // ∣
    // ​
    //  b），那么可以将 a 添加到 S 
    // 1
    // ​
    //   中得到一个更大的整除子集；
    
    // 如果整数 c 是整除子集 S 
    // 2
    // ​
    //   的最大整数 d 的倍数（即 d 
    // ∣
    // ∣
    // ​
    //  c），那么可以将 c 添加到 S 
    // 2
    // ​
    //   中得到一个更大的整除子集。
    
    // 这两点揭示了当前问题状态转移的特点，因此可以使用动态规划的方法求解。题目只要求我们得到多个目标子集的其中一个，根据求解动态规划问题的经验，我们需要将子集的大小定义为状态，然后根据结果倒推得到一个目标子集。事实上，当前问题和使用动态规划解决的经典问题「300. 最长递增子序列」有相似之处。
    
    // 动态规划
    // 根据前言的分析，我们需要将输入数组 nums 按照升序排序，以便获得一个子集的最小整数或者最大整数。又根据动态规划的「无后效性」状态设计准则，我们需要将状态定义成「某个元素必须选择」。
    
    // 状态定义：dp[i] 表示在输入数组 nums 升序排列的前提下，以 nums[i] 为最大整数的「整除子集」的大小（在这种定义下 nums[i] 必须被选择）。
    
    // 状态转移方程：枚举 j=0…i−1 的所有整数 nums[j]，如果 nums[j] 能整除 nums[i]，说明 nums[i] 可以扩充在以 nums[j] 为最大整数的整除子集里成为一个更大的整除子集。
    
    // 初始化：由于 nums[i] 必须被选择，因此对于任意 i=0…n−1，初始的时候 dp[i]=1，这里 n 是输入数组的长度。
    
    // 输出：由于最大整除子集不一定包含 nums 中最大的整数，所以我们需要枚举所有的 dp[i]，选出最大整除子集的大小 maxSize，以及该最大子集中的最大整数 maxVal。按照如下方式倒推获得一个目标子集：
    
    // 倒序遍历数组 dp，直到找到 dp[i]=maxSize 为止，把此时对应的 nums[i] 加入结果集，此时 maxVal=nums[i]；
    
    // 然后将 maxSize 的值减 1，继续倒序遍历找到 dp[i]=maxSize，且 nums[i] 能整除 maxVal 的 i 为止，将此时的 nums[i] 加入结果集，maxVal 更新为此时的 num[i]；
    
    // 重复上述操作，直到 maxSize 的值变成 0，此时的结果集即为一个目标子集。

//     示例
// 假设输入 nums = [1,2,4,8]:

// 排序后数组不变 [1,2,4,8]
// 计算 dp 数组：
// dp[0] = 1
// dp[1] = 2 (因为 2%1=0)
// dp[2] = 3 (因为 4%1=0 和 4%2=0)
// dp[3] = 4 (因为 8%1=0, 8%2=0, 8%4=0)
// maxSize = 4, maxVal = 8
// 构建结果：从后向前找到 dp=4,3,2,1 的元素，得到 [8,4,2,1]
// 反转结果：[1,2,4,8]

// 时间复杂度：O(n^2)，其中 n 是输入数组 nums 的长度。我们需要遍历所有的 dp[i]，并且在每次遍历中都需要遍历 dp[j]，因此时间复杂度为 O(n^2)。
// 空间复杂度：O(n)，我们需要一个 dp 数组来存储每个元素的整除子集大小，因此空间复杂度为 O(n)。
    
