// 3259. 超级饮料的最大强化能量

// 来自未来的体育科学家给你两个整数数组 energyDrinkA 和 energyDrinkB，数组长度都等于 n。这两个数组分别代表 A、B 两种不同能量饮料每小时所能提供的强化能量。

// 你需要每小时饮用一种能量饮料来 最大化 你的总强化能量。然而，如果从一种能量饮料切换到另一种，你需要等待一小时来梳理身体的能量体系（在那个小时里你将不会获得任何强化能量）。

// 返回在接下来的 n 小时内你能获得的 最大 总强化能量。

// 注意 你可以选择从饮用任意一种能量饮料开始。

class Solution {
public:
    using ll = long long;
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector<vector<ll>> d(n + 1, vector<ll>(2, 0));
        for (int i = 1; i <= n; i++) {
            d[i][0] = d[i - 1][0] + energyDrinkA[i - 1];
            d[i][1] = d[i - 1][1] + energyDrinkB[i - 1];
            if (i >= 2) {
                d[i][0] = max(d[i][0], d[i - 2][1] + energyDrinkA[i - 1]);
                d[i][1] = max(d[i][1], d[i - 2][0] + energyDrinkB[i - 1]);
            }
        }
        return max(d[n][0], d[n][1]);
    }
};
