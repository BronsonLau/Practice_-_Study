// 3232. 判断是否可以赢得数字游戏
// 给你一个 正整数 数组 nums。

// Alice 和 Bob 正在玩游戏。在游戏中，Alice 可以从 nums 中选择所有个位数 或 所有两位数，剩余的数字归 Bob 所有。如果 Alice 所选数字之和 严格大于 Bob 的数字之和，则 Alice 获胜。

// 如果 Alice 能赢得这场游戏，返回 true；否则，返回 false。

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int single_digit_sum = 0; // digit表示数字
        int double_digit_sum = 0;
        for (auto num : nums) {
            if (num < 10) {
                single_digit_sum += num;
            } else {
                double_digit_sum += num;
            }
        }
        return single_digit_sum != double_digit_sum;
    }
};

// 思路：
// 1. 统计数字个数，如果个数相等，则无法获胜；
// 2. 其余情况则有可能获胜
// 时间复杂度分析：O(n)。
// 空间复杂度分析：O(1)。