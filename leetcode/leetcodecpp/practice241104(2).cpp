// 633. 平方数之和

// 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c 。

 

class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0;
        long right = (int)sqrt(c);
        while (left <= right)
        {
            long sum = left * left + right * right;
            if (sum == c)  return true;
            else if (sum > c) right --;
            else left++;
        }
        return false;
    }
};

// 双指针法