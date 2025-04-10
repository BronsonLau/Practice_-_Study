// 2999. 统计强大整数的数目

// 给你三个整数 start ，finish 和 limit 。同时给你一个下标从 0 开始的字符串 s ，表示一个 正 整数。
// 如果一个 正 整数 x 末尾部分是 s （换句话说，s 是 x 的 后缀），且 x 中的每个数位至多是 limit ，那么我们称 x 是 强大的 。
// 请你返回区间 [start..finish] 内强大整数的 总数目 。
// 如果一个字符串 x 是 y 中某个下标开始（包括 0 ），到下标为 y.length - 1 结束的子字符串，那么我们称 x 是 y 的一个后缀。比方说，25 是 5125 的一个后缀，但不是 512 的后缀。

// 注意：因为数量级原因，所以无法使用遍历法

// 方法一：数位动态规划
class Solution {
    public:
        long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                      string s) {
            string low = to_string(start);
            string high = to_string(finish);
            int n = high.size();
            low = string(n - low.size(), '0') + low; // 对齐位数
            int pre_len = n - s.size();              // 前缀长度
    
            vector<long long> memo(n, -1);
            std::function<long long(int, bool, bool)> dfs =
                [&](int i, bool limit_low,
                    bool limit_high) -> long long {
                // 递归边界
                if (i == low.size()) {
                    return 1;
                }
    
                if (!limit_low && !limit_high && memo[i] != -1) {
                    return memo[i];
                }
    
                int lo = limit_low ? low[i] - '0' : 0;
                int hi = limit_high ? high[i] - '0' : 9;
    
                long long res = 0;
                if (i < pre_len) {
                    for (int digit = lo; digit <= min(hi, limit); digit++) {
                        res += dfs(i + 1, limit_low && digit == lo,
                                   limit_high && digit == hi);
                    }
                } else {
                    int x = s[i - pre_len] - '0';
                    if (lo <= x && x <= min(hi, limit)) {
                        res =
                            dfs(i + 1, limit_low && x == lo, limit_high && x == hi);
                    }
                }
    
                if (!limit_low && !limit_high) {
                    memo[i] = res;
                }
                return res;
            };
            return dfs(0, true, true);
        }
    };

    // 时间复杂度：O(log(finish)×10)。我们枚举每一个数位能够填入的数字，数位的长度即为 log(finish)，而一位上只有 [0,9] 共 10 个数字。
    // 空间复杂度：O(log(finish))。我们需要一个长度与数位长度相同的数组来记忆化每一个数位的结果。
    


// 方法二：组合数学
class Solution {
    public:
        long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                      string s) {
            string start_ = to_string(start - 1), finish_ = to_string(finish);
            return calculate(finish_, s, limit) - calculate(start_, s, limit);
        }
    
        long long calculate(string x, string s, int limit) {
            if (x.length() < s.length()) {
                return 0;
            }
            if (x.length() == s.length()) {
                return x >= s ? 1 : 0;
            }
    
            string suffix = x.substr(x.length() - s.length(), s.length());
            long long count = 0;
            int preLen = x.length() - s.length();
    
            for (int i = 0; i < preLen; i++) {
                if (limit < (x[i] - '0')) {
                    count += (long)pow(limit + 1, preLen - i);
                    return count;
                }
                count += (long)(x[i] - '0') * (long)pow(limit + 1, preLen - 1 - i);
            }
            if (suffix >= s) {
                count++;
            }
            return count;
        }
    };

// 复杂度分析：
// 时间复杂度：O(log(finish))。遍历 finish 的每一位数来累加组合数。
// 空间复杂度：O(log(finish))。我们需要一个与数位长度相同的数组保存后缀。

