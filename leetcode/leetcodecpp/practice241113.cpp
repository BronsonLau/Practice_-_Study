// 3258. 统计满足 K 约束的子字符串数量 I
// 给你一个 二进制 字符串 s 和一个整数 k。

// 如果一个 二进制字符串 满足以下任一条件，则认为该字符串满足 k 约束：

// 字符串中 0 的数量最多为 k。
// 字符串中 1 的数量最多为 k。
// 返回一个整数，表示 s 的所有满足 k 约束 的
// 子字符串
// 的数量。

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int ans = 0, left = 0, cnt[2]{};
        for (int i = 0; i < s.length(); i++) {
            cnt[s[i] & 1]++;
            while (cnt[0] > k && cnt[1] > k) {
                cnt[s[left] & 1]--;
                left++;
            }
            ans += i - left + 1;
        }
        return ans;
    }
};

// 注意与241112的区别，这里是两个条件，而241112是一个条件