// 3274. 检查棋盘方格颜色是否相同

// 给你两个字符串 coordinate1 和 coordinate2，代表 8 x 8 国际象棋棋盘上的两个方格的坐标。
// 如果这两个方格颜色相同，返回 true，否则返回 false。

// 坐标总是表示有效的棋盘方格。坐标的格式总是先字母（表示列），再数字（表示行）。

class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        return (coordinate1[0] - coordinate2[0] + coordinate1[1] - coordinate2[1]) % 2 == 0;
    }
};

// 方法:一次判断
// 思路与算法

// 由于棋盘上的黑白格是间隔排列的，因此：

// 当行数变化 1 时，格子的颜色会发生变化；
// 当列数变化 1 时，格子的颜色会发生变化。
// 因此，如果两个格子之间行数的差值，与列数的差值，二者的和为偶数，就说明它们的颜色相同，否则颜色不同。记两个格子分别是 c 1和 c 2
// ​，也就是：(c1​[0]−c2[0])+(c1[1]−c2[1])为偶数即可。

