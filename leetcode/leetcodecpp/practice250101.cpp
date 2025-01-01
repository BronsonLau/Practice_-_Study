// 3280. 将日期转换为二进制表示
// 简单

// 给你一个字符串 date，它的格式为 yyyy-mm-dd，表示一个公历日期。

// date 可以重写为二进制表示，只需要将年、月、日分别转换为对应的二进制表示（不带前导零）并遵循 year-month-day 的格式。

// 返回 date 的 二进制 表示。

class Solution {
public:
    string binary(int x) {
        string s;
        while (x) {
            s.push_back('0' + (x & 1));
            x >>= 1;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    string convertDateToBinary(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        return binary(year) + "-" + binary(month) + "-" + binary(day);
    }
};

// 方法一：模拟
// 首先将 date 按照 “yyyy-mm-dd” 的格式解析出年 year、月 month、日 day，然后将 year，month 和 day 的二进制表示字符串用 “-” 连接起来，返回结果。

// 复杂度分析
// 时间复杂度：O(1)。
// 空间复杂度：O(1)。