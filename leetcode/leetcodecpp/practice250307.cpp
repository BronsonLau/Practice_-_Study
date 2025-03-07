// 2597. 美丽子集的数目

// 给你一个由正整数组成的数组 nums 和一个 正 整数 k 。
// 如果 nums 的子集中，任意两个整数的绝对差均不等于 k ，则认为该子数组是一个 美丽 子集。
// 返回数组 nums 中 非空 且 美丽 的子集数目。
// nums 的子集定义为：可以经由 nums 删除某些元素（也可能不删除）得到的一个数组。只有在删除元素时选择的索引不同的情况下，两个子集才会被视作是不同的子集。

 
// 元素较少的回溯法
class Solution {
    public:
        int beautifulSubsets(vector<int>& nums, int k) {
            unordered_map<int, int> cnt;
            int outcome = 0;
            function<void(int)> dfs = [&](int i){
                if (i == nums.size()){
                    outcome++;
                    return ;
                }
                dfs(i + 1);
    
                if (cnt[nums[i] - k] == 0 && cnt[nums[i] + k] == 0){
                    ++cnt[nums[i]];
                    dfs(i + 1);
                    --cnt[nums[i]];
                }
            };
            dfs(0);
            return (outcome - 1);
        }
    };

    // 思路与算法

    // 注意到 nums 的长度范围较小，可以考虑枚举所有子集。
    
    // 枚举子集时，可以考虑是否将第 i 个数加入子集。对于每一个 nums 
    // i
    // ​
    //  ，有两种可能：
    
    // 不将 nums 
    // i
    // ​
    //   添加到子集中，无条件满足。
    // 将 nums 
    // i
    // ​
    //   添加到子集中，需要满足 nums 
    // i
    // ​
    //  −k 和 nums 
    // i
    // ​
    //  +k 还没有被添加到子集中。
    // 为了检查当前子集中已经添加了哪些数，可以使用一个哈希表记录。
    
// 时间复杂度：O(2^n)
// 空间复杂度：O(n)
    