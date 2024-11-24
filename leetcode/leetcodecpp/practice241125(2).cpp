// 743. 网络延迟时间

// 有 n 个网络节点，标记为 1 到 n。

// 给你一个列表 times，表示信号经过 有向 边的传递时间。 times[i] = (ui, vi, wi)，
// 其中 ui 是源节点，vi 是目标节点， wi 是一个信号从源节点传递到目标节点的时间。

// 现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1 。

class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        const int inf = INT_MAX / 2;
        vector<vector<pair<int, int>>> g(n);
        for (auto &t : times) {
            int x = t[0] - 1, y = t[1] - 1;
            g[x].emplace_back(y, t[2]);
        }

        vector<int> dist(n, inf);
        dist[k - 1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.emplace(0, k - 1);
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            int time = p.first, x = p.second;
            if (dist[x] < time) {
                continue;
            }
            for (auto &e : g[x]) {
                int y = e.first, d = dist[x] + e.second;
                if (d < dist[y]) {
                    dist[y] = d;
                    q.emplace(d, y);
                }
            }
        }

        int ans = *max_element(dist.begin(), dist.end());
        return ans == inf ? -1 : ans;
    }
};

// 方法：Dijkstra 算法 (堆优化形式)
// 思路
// 1. 初始化：
//   1）定义一个距离数组 dist，初始化所有元素为正无穷大，
//  2）定义一个优先队列 q，用于存储节点编号和到起点的距离，按距离从小到大排序，
// 3）将起点 k 的距离设置为 0，将起点编号和距离加入优先队列。
// 2. 循环：
//   1）从优先队列 q 中取出一个节点 x，如果 x 已经访问过则跳过。
//   2）将 x 标记为已访问。
//   3）遍历所有节点 y，如果 x 可以到达 y 且通过 x 到达 y 的距离小于 dist[y]，则更新 dist[y] = dist[x] + g[x][y]，将 y 的编号和距离加入优先队列。
// 3. 返回 dist 中的最大值，如果最大值为正无穷大则返回 -1。
// 复杂度分析
// 时间复杂度：O(n+mlogm)，其中 n 是节点个数，m 是边的条数。
// 空间复杂度：O(n+m)，其中 n 是节点个数，m 是边的条数。