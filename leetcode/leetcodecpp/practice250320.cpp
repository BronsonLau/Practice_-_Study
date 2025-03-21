// 补
// 2612. 最少翻转操作数
// 已解答
// 困难
// 相关标签
// 相关企业
// 提示
// 给定一个整数 n 和一个整数 p，它们表示一个长度为 n 且除了下标为 p 处是 1 以外，其他所有数都是 0 的数组 arr。同时给定一个整数数组 banned ，它包含数组中的一些限制位置。在 arr 上进行下列操作：

// 如果单个 1 不在 banned 中的位置上，反转大小为 k 的 子数组。
// 返回一个包含 n 个结果的整数数组 answer，其中第 i 个结果是将 1 放到位置 i 处所需的 最少 翻转操作次数，如果无法放到位置 i 处，此数为 -1 。

// （不会） 方法一：广度优先搜索 + 平衡树
class Solution {
    public:
        vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
            unordered_set<int> ban{banned.begin(), banned.end()};
            set<int> sets[2];
            for (int i = 0; i < n; ++i) {
                if (i != p && !ban.count(i)) {
                    sets[i % 2].insert(i);
                }
            }
            vector<int> ans(n, -1);
            queue<int> q;
            q.push(p);
            ans[p] = 0;
            while (!q.empty()) {
                int i = q.front();
                q.pop();
                int mn = max(i - k + 1, k - i - 1);
                int mx = min(i + k - 1, n * 2 - k - i - 1);
                auto it = sets[mx % 2].lower_bound(mn);
                while (it != sets[mx % 2].end()) {
                    if (*it > mx) {
                        break;
                    }
                    ans[*it] = ans[i] + 1;
                    q.push(*it);
                    it = sets[mn % 2].erase(it);
                }
            }
            return ans;
        }
    };
    
// 时间复杂度：O(nlogn)，平衡树的每次添加删除操作需要 O(logn)。
// 空间复杂度：O(n)。