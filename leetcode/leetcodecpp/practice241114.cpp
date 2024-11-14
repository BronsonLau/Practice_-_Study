// 3249. 统计好节点的数目
// 现有一棵 无向 树，树中包含 n 个节点，按从 0 到 n - 1 标记。树的根节点是节点 0 。给你一个长度为 n - 1 的二维整数数组 edges，其中 edges[i] = [ai, bi] 表示树中节点 ai 与节点 bi 之间存在一条边。

// 如果一个节点的所有子节点为根的 
// 子树
//  包含的节点数相同，则认为该节点是一个 好节点。

// 返回给定树中 好节点 的数量。

// 子树 指的是一个节点以及它所有后代节点构成的一棵树。

class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        int res = 0;
        vector<vector<int>> g(n);
        for (const auto& edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        function<int(int, int)> dfs = [&](int node, int parent) -> int {
            bool valid = true;
            int treeSize = 0;
            int subTreeSize = 0;

            for (int child : g[node]) {
                if (child != parent) {
                    int size = dfs(child, node);
                    if (subTreeSize == 0) {
                        subTreeSize = size;
                    } else if (size != subTreeSize) {
                        valid = false;
                    }
                    treeSize += size;
                }
            }
            if (valid) {
                res++;
            }
            return treeSize + 1;
        };

        dfs(0, -1);
        return res;
    }
};


// 树结构的dfs
// 查找好节点，即子树节点数相同