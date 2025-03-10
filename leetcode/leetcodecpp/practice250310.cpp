// 2269. 找到一个数字的 K 美丽值

// 一个整数 num 的 k 美丽值定义为 num 中符合以下条件的 子字符串 数目：
// 子字符串长度为 k 。
// 子字符串能整除 num 。
// 给你整数 num 和 k ，请你返回 num 的 k 美丽值。

// 注意：
// 允许有 前缀 0 。
// 0 不能整除任何值。
// 一个 子字符串 是一个字符串里的连续一段字符序列。

class Solution {
    public:
        int divisorSubstrings(int num, int k) {
            string s = to_string(num);   // num 十进制表示字符串
            int n = s.size();
            int res = 0;
            for (int i = 0; i <= n - k; ++i) {
                // 枚举所有长度为 k 的子串
                int tmp = stoi(s.substr(i, k));
                if (tmp && num % tmp == 0) {
                    ++res;
                }
            }
            return res;
        }
    };
    

   // 为了方便起见，我们用 s 表示 num 对应十进制表示的字符串。我们可以从左至右枚举 s 中长度为 k 的字符串，并判断该子串对应的整数能否被 num 整除。与此同时，我们用 res 统计能被 num 整除的子串数量，如果某个子串能被 num 整除，则我们将 res 加上 1。最终，res 即为 num 的 k 美丽值，我们返回 res 作为答案。

// 时间复杂度分析： O(n * k )
// 空间复杂度分析： O(n)。