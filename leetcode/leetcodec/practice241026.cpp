// 3181. 执行操作可获得的最大总奖励 II

// 给你一个整数数组 rewardValues，长度为 n，代表奖励的值。

// 最初，你的总奖励 x 为 0，所有下标都是 未标记 的。你可以执行以下操作 任意次 ：

// 从区间 [0, n - 1] 中选择一个 未标记 的下标 i。
// 如果 rewardValues[i] 大于 你当前的总奖励 x，则将 rewardValues[i] 加到 x 上（即 x = x + rewardValues[i]），并 标记 下标 i。
// 以整数形式返回执行最优操作能够获得的 最大 总奖励。



class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        sort(rewardValues.begin(), rewardValues.end());
        if (n >= 2 && rewardValues[n - 2] == rewardValues[n - 1] - 1) {
            return 2 * rewardValues[n - 1] - 1;
        }
        bitset<100000> f0, f1;
        f0[0] = 1;
        for (int i = 0, j = 0; i < n; i++) {
            while (j < rewardValues[i]) {
                f1[j] = f0[j];
                j++;
            }
            f0 |= f1 << rewardValues[i];
        }
        int res = 0;
        for (int i = 0; i < f0.size(); i++) {
            if (f0[i]) {
                res = i;
            }
        }
        return res;
    }
};

// 位运算优化 + 动态规划
// 记 rewardValues 的最大值为 m，因为最后一次操作前的总奖励一定小于等于 m−1，所以可获得的最大总奖励小于等于 2m−1。

// 如果 rewardValues 中存在 m−1，那么结果必定为 2m−1，可以直接返回结果。

// 假设上一次操作选择的奖励值为 x 
// // ​
//  ，那么执行操作后的总奖励 x≥x 
// 
// ​
//  ，根据题意，后面任一操作选择的奖励值 x 
// 
// ​
//   一定都大于 x，从而有 x 
// 
// ​
//  >x 
// 
// ​
//  ，因此执行的操作是按照奖励值单调递增的。

// 首先将 rewardValues 从小到大进行排序，使用 dp[k] 表示总奖励 k 是否可获得，初始时 dp[0]=1，表示不执行任何操作获得总奖励 0。然后我们对 rewardValues 进行遍历，令当前值为 x，那么对于 k∈[x,2x−1]（将 k 倒序枚举），将 dp[k] 更新为 dp[k−x] ∣ dp[k]（符号 ∣ 表示或操作），表示先前的操作可以获得总奖励 k−x，那么加上 x 后，就可以获取总奖励 k。

// 要根据以上推断，一次操作前后的 dp 数组（分别记为 f 
// 1
// ​
//   和 f 
// 0
// ​
//  ）之前的递推关系为：

// f 
// 0
// ​
//  [k]=f 
// 1
// ​
//  [k−x] ∣ f 
// 0
// ​
//  [k],k∈[x,2x−1]
// 可以用位运算表示为 f 
// 0
// ​
//  =(mask 
// x
// ​
//  (f 
// 1
// ​
//  )≪x) ∣ f 
// 0
// ​
//  ，其中 mask 
// x
// ​
//  (f 
// 1
// ​
//  ) 函数表示取 f 
// 1
// ​
//   的低 x 位。因此我们可以使用位运算对动态规划进行优化，降低时间复杂度。