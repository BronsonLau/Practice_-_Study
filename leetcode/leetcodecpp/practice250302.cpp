// 132. 分割回文串 II
// 给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文串。
// 返回符合要求的 最少分割次数 。


// 动态规划法
class Solution {
    public:
        int minCut(string s) {
            int n = s.size();
            vector<vector<int>> g(n, vector<int>(n,true));
    
            for(int i = n - 1; i>= 0; --i ){
                for(int j = i + 1; j < n; ++j){
                    g[i][j] = (s[i] == s[j]) && g[i + 1][j - 1];
                }
            }
    
            vector<int> f(n, 100001);
            for(int i = 0; i < n; ++i)
            {
                if(g[0][i]){
                    f[i] = 0;
                }
                else{
                    for (int j = 0; j < i; ++j){
                        if(g[j + 1][i]){
                            f[i] = min(f[i], f[j] + 1);
                        }
                    }
                }
            }
    
            return f[n - 1];
        }
    };

// 难点：min条件判断
// 此处的意思是  我们枚举最后一个回文串的起始位置 j+1，保证 s[j+1..i] 是一个回文串，那么 f[i] 就可以从 f[j] 转移而来，附加 1 次额外的分割次数。

// 时间复杂度：O(n^2)
// 空间复杂度：O(n^2)