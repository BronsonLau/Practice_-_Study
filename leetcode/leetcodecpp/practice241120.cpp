// 3244. 新增道路查询后的最短距离 II
// 已解答
// 困难
// 相关标签
// 相关企业
// 给你一个整数 n 和一个二维整数数组 queries。

// 有 n 个城市，编号从 0 到 n - 1。初始时，每个城市 i 都有一条单向道路通往城市 i + 1（ 0 <= i < n - 1）。

// queries[i] = [ui, vi] 表示新建一条从城市 ui 到城市 vi 的单向道路。每次查询后，你需要找到从城市 0 到城市 n - 1 的最短路径的长度。

// 所有查询中不会存在两个查询都满足 queries[i][0] < queries[j][0] < queries[i][1] < queries[j][1]。

// 返回一个数组 answer，对于范围 [0, queries.length - 1] 中的每个 i，answer[i] 是处理完前 i + 1 个查询后，从城市 0 到城市 n - 1 的最短路径的长度。

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> roads(n);
        iota(roads.begin(), roads.end(), 1);
        vector<int> res;
        int dist = n - 1;
        for (auto &query : queries) {
            int k = roads[query[0]];
            roads[query[0]] = query[1];
            while (k != -1 && k < query[1]) {
                int t = roads[k];
                roads[k] = -1;
                k = t;
                dist--;
            }
            res.push_back(dist); 
        }
        return res;
    }
};

// 方法：贪心算法
// 步骤：
// 1. 初始化一个长度为 n 的数组 roads，用于表示城市之间的道路关系。roads[i] 表示城市 i 到城市 i + 1 的道路。
// 2. 遍历所有操作，对于每个操作，更新 roads 数组，同时更新 dist 变量，表示从城市 0 到城市 n - 1 的最短路径的长度。
// 3. 返回结果数组 res。
// 时间复杂度：O(nq)，其中 n 是城市的数量，q 是操作的数量。
// 空间复杂度：O(n)。

