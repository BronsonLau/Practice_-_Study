// 2680. 最大或值
// 给你一个下标从 0 开始长度为 n 的整数数组 nums 和一个整数 k 。每一次操作中，你可以选择一个数并将它乘 2 。

// 你最多可以进行 k 次操作，请你返回 nums[0] | nums[1] | ... | nums[n - 1] 的最大值。

// a | b 表示两个整数 a 和 b 的 按位或 运算。

// 方法一：贪心 + 前缀和
class Solution {
    public:
        using ll = long long;
        long long maximumOr(vector<int>& nums, int k) {
            int n = nums.size();
            vector<ll> suf(n + 1, 0);
            
            for (int i = n - 1; i >= 0; i--) {
                suf[i] = suf[i + 1] | nums[i];
            }
    
            ll res = 0;
            ll pre = 0;
            for (int i = 0; i < n; i++) {
                res = max(res, pre | (1ll * nums[i] << k) | suf[i + 1]);
                pre |= nums[i];
            }
            return res;
        }
    };
    
    // 时间复杂度：O(n)，其中 n 是 nums 的长度。计算后缀或值数组的时间复杂度为 O(n)，枚举单个整数的时间复杂度为 O(1)，总共枚举了 n 次，因此总体时间复杂度为 O(n)。

    // 空间复杂度：O(n)。后缀或值数组的空间复杂度为 O(n)。
