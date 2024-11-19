// 3243. 新增道路查询后的最短距离 I
// 给你一个整数 n 和一个二维整数数组 queries。

// 有 n 个城市，编号从 0 到 n - 1。初始时，每个城市 i 都有一条单向道路通往城市 i + 1（ 0 <= i < n - 1）。

// queries[i] = [ui, vi] 表示新建一条从城市 ui 到城市 vi 的单向道路。每次查询后，你需要找到从城市 0 到城市 n - 1 的最短路径的长度。

// 返回一个数组 answer，对于范围 [0, queries.length - 1] 中的每个 i，answer[i] 是处理完前 i + 1 个查询后，从城市 0 到城市 n - 1 的最短路径的长度。

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &queries) {
        vector<vector<int>> neighbors(n);
        for (int i = 0; i < n - 1; i++) {
            neighbors[i].push_back(i + 1);
        }
        vector<int> res;
        for (auto &query : queries) {
            neighbors[query[0]].push_back(query[1]);
            res.push_back(bfs(n, neighbors));
        }
        return res;
    }

    int bfs(int n, const vector<vector<int>> &neighbors) {
        vector<int> dist(n, -1);
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y : neighbors[x]) {
                if (dist[y] >= 0) {
                    continue;
                }
                q.push(y);
                dist[y] = dist[x] + 1;
            }
        }
        return dist[n - 1];
    }
};

// 方法：bfs
// 1. 构建邻接表，将所有节点的相邻节点加入到邻接表中，注意：n-1个节点之间有n-1条边，所以需要将n-1加入到邻接表中
// 2. 使用bfs算法
// 3. 遍历所有查询，每次查询都调用bfs算法，返回结果
// 时间复杂度：O(n^2)，其中n是节点的数量，每次bfs算法的时间复杂度为O(n)
// 空间复杂度：O(n)
