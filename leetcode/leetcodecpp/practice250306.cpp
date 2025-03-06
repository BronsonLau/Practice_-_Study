// 2588. 统计美丽子数组数目

// 给你一个下标从 0 开始的整数数组nums 。每次操作中，你可以：
// 1.选择两个满足 0 <= i, j < nums.length 的不同下标 i 和 j 。
// 2.选择一个非负整数 k ，满足 nums[i] 和 nums[j] 在二进制下的第 k 位（下标编号从 0 开始）是 1 。
// 3.将 nums[i] 和 nums[j] 都减去 2k 。

// 如果一个子数组内执行上述操作若干次后，该子数组可以变成一个全为 0 的数组，那么我们称它是一个 美丽 的子数组。
// 请你返回数组 nums 中 美丽子数组 的数目。
// (子数组是一个数组中一段连续非空的元素序列。)

// 前缀和法
class Solution {
    public:
        long long beautifulSubarrays(vector<int>& nums) {
            unordered_map<int, int>cnt;
            int mask = 0;
            long long ans = 0;
            cnt[0] = 1;
            for (int x : nums){
                mask ^= x;
                ans += cnt[mask];
                cnt[mask]++;
    
            }
            return ans;
        }
    };

// 时间复杂度：O(n)，其中 n 表示给定数组 nums 的长度。我们只需遍历一遍数组即可，需要的时间为 O(n)。

// 空间复杂度：O(n)，其中 n 表示给定数组 nums 的长度。需要存储数组中前 i 个元素异或的值，需要的空间为 O(n)。

