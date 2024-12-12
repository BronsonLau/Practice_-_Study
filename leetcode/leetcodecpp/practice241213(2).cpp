// 3264. K 次乘运算后的最终数组 I
// 简单

// 给你一个整数数组 nums ，一个整数 k  和一个整数 multiplier 。

// 你需要对 nums 执行 k 次操作，每次操作中：

// 找到 nums 中的 最小 值 x ，如果存在多个最小值，选择最 前面 的一个。
// 将 x 替换为 x * multiplier 。
// 请你返回执行完 k 次乘运算之后，最终的 nums 数组。

class Solution {
public:
    long long quickMul(long long x, long long y, long long m) {
        long long res = 1;
        while (y) {
            if (y & 1) {
                res = (res * x) % m;
            }
            y >>= 1;
            x = (x * x) % m;
        }
        return res;
    }

    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) {
            return nums;
        }
        long long n = nums.size(), m = 1e9 + 7;
        long long mx = *max_element(nums.begin(), nums.end());
        vector<pair<long long, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {nums[i], i};
        }
        make_heap(v.begin(), v.end(), greater<>());
        for (; v[0].first < mx && k; k--) {
            pop_heap(v.begin(), v.end(), greater<>());
            v.back().first *= multiplier;
            push_heap(v.begin(), v.end(), greater<>());
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            int t = k / n + (i < k % n);
            nums[v[i].second] = ((v[i].first % m) * quickMul(multiplier, t, m)) % m;
        }
        return nums;
    }
};

// 方法二：优先队列
// 假设初始时，数组 nums 的最大值为 mx。首先将数组的所有元素及对应的下标都放到优先队列（最小堆，排序规则按照元素值、下标升序）中，然后不断从优先队列中取出元素，执行乘 multiplier 操作后，再放回优先队列中。那么有以下两种情况：

// 情况一

// 每次取出的元素 x，都有 x×multiplier<mx，直到 k=0 成立。对于这类情况，数组后续无需执行任何操作，我们直接返回操作后的数组。

// 情况二

// 如果对于堆顶元素 x，有 x≥mx，我们直接终止以上操作。那么对于优先队列中的任一元素值 y，都有 mx×multiplier>y≥mx（假设 mx×multiplier≤y，那么执行操作前 y 对应的元素值为  
// multiplier
// y
// ​
//  ≥mx，矛盾）。

// 此时按照规则，优先队列中值最小同时下标最小的堆顶元素是下一次操作要选择的元素，我们对它执行操作后，后续需要对其余所有元素都恰好执行一次操作后，才会再次对它执行操作。

// 这里简单论证一下，当我们对堆顶元素执行操作后，它的值变成 multiplier×mx，是大于任一其余元素的，所以必须对其余所有元素执行至少一次操作后，才会再次对它执行操作；然后对于任一其余元素 y，执行操作后，有 y×multiplier≥multiplier×mx，当且仅当 y 的下标大于堆顶元素的下标时，等号成立，所以元素 y 最多执行一次操作，得证。

// 根据以上推导，后续的操作可以先批量对数组整体执行 ⌊ 
// n
// k
// ​
//  ⌋ 次操作，然后再按照规则单个执行 kmodn 次操作，具体实现为快速幂算法 + 排序。

// 时间复杂度：O(n×(lognlogmx+log 
// n
// k
// ​
//  ))。其中 n 是数组 nums 的长度，k 是操作次数，mx 是数组 nums 的最大值。优先队列的出队和入队每个元素最多执行的次数为 O(logmx)，所以时间复杂度为 O(nlognlogmx)；批量执行时，每个元素执行一次的时间复杂度为 O(log 
// n
// k
// ​
//  )，所以时间复杂度为 O(nlog 
// n
// k
// ​
//  )。

// 空间复杂度：O(n)。主要为优先队列需要的空间

