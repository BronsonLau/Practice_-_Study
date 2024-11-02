// 3226. 使两个整数相等的位更改次数

// 给你两个正整数 n 和 k。

// 你可以选择 n 的 二进制表示 中任意一个值为 1 的位，并将其改为 0。

// 返回使得 n 等于 k 所需要的更改次数。如果无法实现，返回 -1。

 
class Solution {
public:
    int minChanges(int n, int k) {
        return (n & k) == k ? __builtin_popcount(n ^ k) : -1;
    }
};

// 位运算方法，采用与运算直接得出结论