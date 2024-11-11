// 1547. 切棍子的最小成本
// 有一根长度为 n 个单位的木棍，棍上从 0 到 n 标记了若干位置。
// 给你一个整数数组 cuts ，其中 cuts[i] 表示你需要将棍子切开的位置。
// 你可以按顺序完成切割，也可以根据需要更改切割的顺序。
// 每次切割的成本都是当前要切割的棍子的长度，切棍子的总成本是历次切割成本的总和。
// 对棍子进行切割将会把一根木棍分成两根较小的木棍（这两根木棍的长度和就是切割前木棍的长度）。
// 返回切棍子的 最小总成本 。

 

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        vector<vector<int>> f(m + 2, vector<int>(m + 2));
        for (int i = m; i >= 1; --i) {
            for (int j = i; j <= m; ++j) {
                f[i][j] = (i == j ? 0 : INT_MAX);
                for (int k = i; k <= j; ++k) {
                    f[i][j] = min(f[i][j], f[i][k - 1] + f[k + 1][j]);
                }
                f[i][j] += cuts[j + 1] - cuts[i - 1];
            }
        }
        return f[1][m];
    }
};

// 困难版dp
