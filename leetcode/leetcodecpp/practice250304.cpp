// 1745. 分割回文串 IV
// // 困难

// 给你一个字符串 s ，如果可以将它分割成三个 非空 回文子字符串，那么返回 true ，否则返回 false 。
// 当一个字符串正着读和反着读是一模一样的，就称其为 回文字符串 。

// 动态规划法 + 统计
class Solution {
    public:
        bool checkPartitioning(string s) {
            int n = s.size();
            vector<vector<bool>> isPalindrome(n, vector<bool>(n));
            for (int l = 1; l < n; l++){
                for (int p1 = 0; p1 <= n - l; p1++){
                    int p2 = p1 + l - 1;
                    if (l == 1) isPalindrome[p1][p2] = true;
                    else if (l == 2) isPalindrome[p1][p2] = (s[p1] == s[p2]);
                    else isPalindrome[p1][p2] = (s[p1] == s[p2] && isPalindrome[p1 + 1][p2 - 1]);
                }
            }
    
            for (int p1 = 1; p1 < n - 1; p1++){
                if(!isPalindrome[0][p1 - 1]) continue;
    
                for(int p2 = p1; p2 < n - 1; p2++){
                    if(isPalindrome[p1][p2] && isPalindrome[p2 + 1][n - 1]) return true;
                }
            }
            return false;
        }
    };

    // 设字符串的长度为 n，首先我们用动态规划算出 s 的任意一个子字符串是否为回文串，并将结果保存在二维数组中。这一步中，我们使用双重循环来计算，第一层循环遍历长度 length，从短到长；第二层循环遍历子字符串的起始位置。
    // 判断某个子字符串是否为回文时，如果长度为 1，则一定为回文；如果长度为 2，则判断这两个字符是否相同；如果长度为 3，则需要首尾两个字符相同并且剩余的字符串也为回文。
    // 每次判断长串时，直接查询已存储的短串状态，避免了重复计算。
    // 遍历完成后，所有子串的回文状态均已确定，可在常数时间内查询任意子串是否为回文。

    // 接下来需要判断是否存在三个非空回文子串，拼接起来可以构成完整的 s。我们只需要遍历中间子字符串的起始位置和终点位置，这两个位置确定后，三个子串都确定了。
    // 如果三个子串都是回文，则返回 true，否则返回 false。
    
    // 时间复杂度：O(n^2)
    // 空间复杂度：O(n^2)
    