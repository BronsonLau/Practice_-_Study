// 3110. 字符串的分数

// 给你一个字符串 s 。一个字符串的 分数 定义为相邻字符 ASCII 码差值绝对值的和。
// 请你返回 s 的 分数 。

// 简单的模拟题
class Solution {
    public:
        int scoreOfString(string s) {
            int n = s.size();
            int score = 0;
            for (int i = 0; i + 1 < n; ++i) {
                score += abs(s[i] - s[i + 1]);
            }
            return score;
        }
    };
    
    int main() {
        Solution sol;
        string s = "abc";
        int score = sol.scoreOfString(s);
        cout << "score: " << score << endl;
        return 0;
    }    


// 时间复杂度：O(n)，其中 n 是字符串 s 的长度。
// 空间复杂度：O(1)。