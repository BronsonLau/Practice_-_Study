// 743. 网络延迟时间

// 有 n 个网络节点，标记为 1 到 n。

// 给你一个列表 times，表示信号经过 有向 边的传递时间。 times[i] = (ui, vi, wi)，
// 其中 ui 是源节点，vi 是目标节点， wi 是一个信号从源节点传递到目标节点的时间。

// 现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1 。

class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        const int inf = INT_MAX / 2;
        vector<vector<int>> g(n, vector<int>(n, inf));
        for (auto &t : times) {
            int x = t[0] - 1, y = t[1] - 1;
            g[x][y] = t[2];
        }

        vector<int> dist(n, inf);
        dist[k - 1] = 0;
        vector<int> used(n);
        for (int i = 0; i < n; ++i) {
            int x = -1;
            for (int y = 0; y < n; ++y) {
                if (!used[y] && (x == -1 || dist[y] < dist[x])) {
                    x = y;
                }
            }
            used[x] = true;
            for (int y = 0; y < n; ++y) {
                dist[y] = min(dist[y], dist[x] + g[x][y]);
            }
        }

        int ans = *max_element(dist.begin(), dist.end());
        return ans == inf ? -1 : ans;
    }
};

// 方法：Dijkstra 算法 (枚举形式)
// 思路
// 1. 初始化：
//    1）定义一个距离数组 dist，初始化所有元素为正无穷大，
//    2）定义一个访问数组 used，初始化所有元素为 false，
//    3）将起点 k 的距离设置为 0。
// 2. 循环：
//    1）找到距离起点最近的未访问节点 x，即找到 dist 中最小的非负值对应的下标。
//    2）将 x 标记为已访问。
//    3）遍历所有节点 y，更新 dist[y] = min(dist[y], dist[x] + g[x][y])。
// 3. 返回 dist 中的最大值，如果最大值为正无穷大则返回 -1。


// 复杂度分析
// 时间复杂度：O(n^2)，其中 n 是节点个数。
// 空间复杂度：O(n)，其中 n 是节点个数。