// 1278. 分割回文串 III

// 给你一个由小写字母组成的字符串 s，和一个整数 k。
// 请你按下面的要求分割字符串：
// 1. 你可以将 s 中的部分字符修改为其他的小写英文字母。
// 2. 你需要把 s 分割成 k 个非空且不相交的子串，并且每个子串都是回文串。
// 请返回以这种方式分割字符串所需修改的最少字符数。

// 动态规划法

class Solution {
    public:
        int cost(string& s, int l, int r){
            int ret = 0;
            for (int i = l, j = r; i < j; ++i, --j){
                if (s[i] != s[j]) ++ret;
            }
            return ret;
        }
        int palindromePartition(string s, int k) {
            int n = s.size();
            vector<vector<int>> f(n + 1, vector<int>(k + 1, INT_MAX));
            f[0][0] = 0;
            for (int i = 1; i <= n; ++i){
                for (int j = 1; j <= min(k, i); ++j){
                    if (j == 1) f[i][j] = cost(s, 0, i - 1);
                    else{
                        for (int i0 = j - 1; i0 < i; ++i0){
                            f[i][j] = min(f[i][j], f[i0][j - 1] + cost(s, i0, i - 1));
                        }
                    }
                }
            }
            return f[n][k];
        }
    };

// 时间复杂度：O(n^3 * k)
// 空间复杂度：O(n * k)