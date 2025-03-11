// 2012. 数组美丽值求和

// 给你一个下标从 0 开始的整数数组 nums 。对于每个下标 i（1 <= i <= nums.length - 2），nums[i] 的 美丽值 等于：
// 2，对于所有 0 <= j < i 且 i < k <= nums.length - 1 ，满足 nums[j] < nums[i] < nums[k]
// 1，如果满足 nums[i - 1] < nums[i] < nums[i + 1] ，且不满足前面的条件
// 0，如果上述条件全部不满足
// 返回符合 1 <= i <= nums.length - 2 的所有 nums[i] 的 美丽值的总和 。

class Solution {
    public:
        int sumOfBeauties(vector<int>& nums) {
            int n = nums.size();
            vector<int> state(n);
            int pre_max = nums[0];
            for (int i = 1; i < n - 1; i++) {
                if (nums[i] > pre_max) {
                    state[i] = 1;
                    pre_max = nums[i];
                }
            }
            int suf_min = nums[n - 1];
            int res = 0;
            for (int i = n - 2; i > 0; i--) {
                if (state[i] && nums[i] < suf_min) {
                    res += 2;
                } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                    res += 1;
                }
                suf_min = min(suf_min, nums[i]);
            }
            return res;
        }
    };
    
// 第一次遍历判断共性条件
// 第二次遍历判断美丽值多少
// 直接维护res进行相加

// 时间复杂度分析： O(n)
// 空间复杂度分析： O(n)