// 3083. 字符串及其反转中是否存在同一子字符串
// 简单

// 给你一个字符串 s ，请你判断字符串 s 是否存在一个长度为 2 的子字符串，在其反转后的字符串中也出现。

// 如果存在这样的子字符串，返回 true；如果不存在，返回 false 。

class Solution {
public:
    bool isSubstringPresent(string s) {
        for (int i = 0; i + 1 < s.size(); i++) {
            string substr = s.substr(i, 2);
            reverse(substr.begin(), substr.end());
            if (s.find(substr) != string::npos) {
                return true;
            }
        }
        return false;
    }
};


// 方法一：一次遍历
// 思路与算法:
// 遍历字符串中每个长度为 2 的子串，将其翻转后判断是否在原串中出现即可。


// 时间复杂度：O(n^2)，其中 n 是字符串的长度。总共有 O(n) 个长度为 2 的子串，每次查找其翻转后的字符串是否在原字符串中出现的时间复杂度为 O(n)
// 空间复杂度：O(1)。

