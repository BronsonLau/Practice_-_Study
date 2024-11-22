// 3233. 统计不是特殊数字的数字数量
// 给你两个 正整数 l 和 r。对于任何数字 x，x 的所有正因数（除了 x 本身）被称为 x 的 真因数。

// 如果一个数字恰好仅有两个 真因数，则称该数字为 特殊数字。例如：

// 数字 4 是 特殊数字，因为它的真因数为 1 和 2。
// 数字 6 不是 特殊数字，因为它的真因数为 1、2 和 3。
// 返回区间 [l, r] 内 不是 特殊数字 的数字数量。

class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int n = sqrt(r);
        vector<int> v(n + 1);
        int res = r - l + 1;
        for (int i = 2; i <= n; i++) {
            if (v[i] == 0) {
                if (i * i >= l && i * i <= r) {
                    res--;
                }
                for (int j = i * 2; j <= n; j += i) {
                    v[j] = 1;
                }
            }
        }
        return res;
    }
};

// 方法：埃氏筛
// 步骤：
// 1. 初始化一个变量 n，表示 r 的平方根。
// 2. 初始化一个数组 v，大小为 n + 1，用于标记是否为质数。
// 3. 初始化一个变量 res，表示不是特殊数字的数量，初始值为 r - l + 1。
// 4. 遍历 2 到 n，对于每个 i，如果 v[i] 为 0，表示 i 是质数，那么：
//     - 如果 i 的平方在 [l, r] 之间，那么 res 减一。
//     - 将 i 的所有倍数标记为非质数。
// 5. 返回 res。
// 时间复杂度：O(nloglogn)，其中 n 是 r 的平方根。
// 空间复杂度：O(n)。
// 提示：
// 1 <= l <= r <= 10^6
// https://leetcode.cn/problems/count-primes