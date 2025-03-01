// 131.给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

class Solution {

    private:
        vector<vector<int>> f;
        vector<vector<string>> ret;
        vector<string> ans;
        int n;
    
    public:
        void dfs(const string &s, int i)
        {
            if (i == n)
            {
                ret.push_back(ans);
                return ;
            }
    
            for (int j = i; j < n; ++j)
            {
                if(f[i][j])
                {
                    ans.push_back(s.substr(i, j - i + 1));
                    dfs(s, j + 1);
                    ans.pop_back();
                }
            }
        }
    
        vector<vector<string>> partition(string s) {
            n = s.size();
            f.assign(n, vector<int>(n, true));
    
            for (int i = n - 1; i >= 0; --i)
            {
                for(int j = i + 1; j < n; ++j)
                {
                    f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
                }
            } 
    
            dfs(s, 0);
            return ret;       
        }
    };

// 时间复杂度：O(n⋅2^n)
// 空间复杂度：O(n^2)

// 35-41行是预先筛选可能的回文串
// 再对每个可能的回文串进行dfs
// 递归的终止条件是i==n