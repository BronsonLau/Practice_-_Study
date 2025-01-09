// 3297. 统计重新排列后包含另一个字符串的子字符串数目 I
// 中等

// 给你两个字符串 word1 和 word2 。
// 如果一个字符串 x 重新排列后，word2 是重排字符串的 前缀，那么我们称字符串 x 是 合法的 。

// 请你返回 word1 中 合法 子字符串的数目。

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> count(26, 0);
        for (auto c : word2) {
            count[c - 'a']++;
        }

        int n = word1.size();
        vector<vector<int>> pre_count(n + 1, vector<int>(26, 0));
        for (int i = 1; i <= n; i++) {
            pre_count[i].assign(pre_count[i - 1].begin(), pre_count[i - 1].end());
            pre_count[i][word1[i - 1] - 'a']++;
        }

        auto get = [&](int l, int r) {
            int border = l;
            while (l < r) {
                int m = l + r >> 1;
                bool f = true;
                for (int i = 0; i < 26; i++) {
                    if (pre_count[m][i] - pre_count[border - 1][i] < count[i]) {
                        f = false;
                        break;
                    }
                }
                if (f) {
                    r = m;
                } else {
                    l = m + 1;
                }
            }
            return l;
        };

        long long res = 0;
        for (int l = 1; l <= n; l++) {
            int r = get(l, n + 1);
            res += n - r + 1;
        }
        return res;
    }
};

// 方法一：哈希表 + 二分
// 思路与算法

// 我们的目标是求解 word1 中有多少子串经过重新排列后存在一个前缀是 word2，也就是说要求解有多少子串包含 word2 中的全部字符。
// 对于每个 l(1≤l≤n)，找到最小的 r(l≤r≤n)，使得 word1 区间 [l,r] 内包含 word2 的全部字符，可以发现子串 [l,r+1],[l,r+2],⋯,[l,n] 都是满足要求的，计数 n−r+1 。将所有的计数都加起来就是答案。
// 而找到每个 l 对应的最小的 r 可以使用二分算法，我们提前预处理出 word2 中所有字符的出现次数，再预处理 word1 每个前缀中每种字符的出现次数。因此在二分查找 r 的过程中，可以 O(C) 时间判断是否满足要求（C 是字符数量，此处等于 26），而那个最小的那个满足要求的下标就是我们要找的 r。
// 由于本方法时间复杂度较高，有些语言可能会超时，建议学习方法二。

// 复杂度分析

// 时间复杂度：O(nClogn+m)，其中 n 是 word1 的长度，m 是 word2 的长度，C 是字符种类数，此题中等于 26。初始化的时间复杂度分别为 O(m) 和 O(nC)，每次二分的时间复杂度为 O(Clogn)，因此总的时间复杂度为 O(nClogn+m)。
// 空间复杂度：O(nC)。

