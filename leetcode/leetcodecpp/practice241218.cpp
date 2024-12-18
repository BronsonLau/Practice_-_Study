// 3292. 形成目标字符串需要的最少字符串数 II
// 困难

// 给你一个字符串数组 words 和一个字符串 target。

// 如果字符串 x 是 words 中 任意 字符串的 
// 前缀
// ，则认为 x 是一个 有效 字符串。

// 现计划通过 连接 有效字符串形成 target ，请你计算并返回需要连接的 最少 字符串数量。如果无法通过这种方式形成 target，则返回 -1。

class Solution {
public:
    int minValidStrings(vector<string>& words, string target) {
        auto prefix_function = [](const string& word, const string& target) -> vector<int> {
            string s = word + '#' + target;
            int n = s.size();
            vector<int> pi(n, 0);
            for (int i = 1; i < n; i++) {
                int j = pi[i - 1];
                while (j > 0 && s[i] != s[j]) {
                    j = pi[j - 1];
                }
                if (s[i] == s[j]) {
                    j++;
                }
                pi[i] = j;
            }
            return pi;
        };

        int n = target.size();
        vector<int> back(n, 0);
        for (const string& word : words) {
            vector<int> pi = prefix_function(word, target);
            int m = word.size();
            for (int i = 0; i < n; i++) {
                back[i] = max(back[i], pi[m + 1 + i]);
            }
        }

        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = 1e9;
        }
        for (int i = 0; i < n; i++) {
            dp[i + 1] = dp[i + 1 - back[i]] + 1;
            if (dp[i + 1] > n) {
                return -1;
            }
        }
        return dp[n];
    }
};

// 方法一：KMP + 动态规划
// 思路与算法

// 首先我们对每一个 words 中的单词和 target 使用「Knuth–Morris–Pratt」 算法，可以求出对于结束在 target[i] 的前缀，所能够匹配单词的最长前缀 back[i]。

// 然后我们用「动态规划」解决本题目，用 dp[i] 表示形成前 n 个字母需要的最少字符串数。初始化 dp[0] 为零，其他为大整数。因为题目的性质可以观察到，dp 是单调递增数列，并推导递推公式 dp[i+1]=dp[i+1−back[i]]+1。

// 最后返回 dp[n] 为结果。

// 时间复杂度：O(k×(m+n))，其中 k 是数组的长度，m 是单词的长度，n 是 target 长度。

// 空间复杂度：O(m+n)，其中 m 是单词的长度，n 是 target 长度。


