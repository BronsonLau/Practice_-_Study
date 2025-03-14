// 3340. 检查平衡字符串

// 给你一个仅由数字 0 - 9 组成的字符串 num。如果偶数下标处的数字之和等于奇数下标处的数字之和，则认为该数字字符串是一个 平衡字符串。
// 如果 num 是一个 平衡字符串，则返回 true；否则，返回 false。


// ...

class Solution {
    public:
        bool isBalanced(string num) {
            int diff = 0; 
            int sign = 1;
            for (char c : num){
                int d = c - '0';
                diff += sign * d;
                sign = -sign;
            }
    
            return (diff == 0);
        }
    };


// 时间复杂度：O(n)，其中 n 是 num 的长度。
// 空间复杂度：O(1)。