// 633. 平方数之和

// 给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a^2 + b^2 = c 。

 

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++)
        {
            double b = sqrt(c - a * a);
            if ( b == (int)b )
            {
                return true;
            }
        }
        return false;
    }
};

// 直接枚举平方数法