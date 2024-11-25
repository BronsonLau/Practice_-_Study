// 3206. 交替组 I
// 给你一个整数数组 colors ，它表示一个由红色和蓝色瓷砖组成的环，第 i 块瓷砖的颜色为 colors[i] ：

// colors[i] == 0 表示第 i 块瓷砖的颜色是 红色 。
// colors[i] == 1 表示第 i 块瓷砖的颜色是 蓝色 。
// 环中连续 3 块瓷砖的颜色如果是 交替 颜色（也就是说中间瓷砖的颜色与它 左边 和 右边 的颜色都不同），那么它被称为一个 交替 组。

// 请你返回 交替 组的数目。

// 注意 ，由于 colors 表示一个 环 ，第一块 瓷砖和 最后一块 瓷砖是相邻的。

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (colors[i] != colors[(i - 1 + n) % n] && colors[i] != colors[(i + 1) % n]) {
                res += 1;
            }
        }
        return res;
    }
};

// 思路
// 枚举每个位置，判断是否为交替组，如果为交替组，则计数器加1
// 时间复杂度分析：O(n)，其中 n 是数组 colors 的长度。
// 空间复杂度分析：O(1)。

