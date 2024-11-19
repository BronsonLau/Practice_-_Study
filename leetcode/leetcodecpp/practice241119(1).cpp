// 3243. 新增道路查询后的最短距离 I
// 给你一个整数 n 和一个二维整数数组 queries。

// 有 n 个城市，编号从 0 到 n - 1。初始时，每个城市 i 都有一条单向道路通往城市 i + 1（ 0 <= i < n - 1）。

// queries[i] = [ui, vi] 表示新建一条从城市 ui 到城市 vi 的单向道路。每次查询后，你需要找到从城市 0 到城市 n - 1 的最短路径的长度。

// 返回一个数组 answer，对于范围 [0, queries.length - 1] 中的每个 i，answer[i] 是处理完前 i + 1 个查询后，从城市 0 到城市 n - 1 的最短路径的长度。

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries) {
        vector<vector<int>> prev(n);
        vector<int> dp(n);
        for (int i = 1; i < n; i++) {
            prev[i].push_back(i - 1);
            dp[i] = i;
        }
        vector<int> res;
        for (auto &query : queries) {
            prev[query[1]].push_back(query[0]);
            for (int v = query[1]; v < n; v++) {
                for (int u : prev[v]) {
                    dp[v] = min(dp[v], dp[u] + 1);
                }
            }
            res.push_back(dp[n - 1]);
        }
        return res;
    }
};

// 方法：动态规划
// 1. 构建一个数组prev，记录每个位置的前一个位置，初始时，每个位置的前一个位置是它的前一个位置
// 2. 遍历所有操作，对于每个操作，更新dp数组，同时更新prev数组
// 3. 返回dp数组的最后一个元素
// 时间复杂度：O(nq)
// 空间复杂度：O(nq) 
