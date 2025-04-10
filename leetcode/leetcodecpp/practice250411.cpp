// 2843. 统计对称整数的数目
// 给你两个正整数 low 和 high 。
// 对于一个由 2 * n 位数字组成的整数 x ，如果其前 n 位数字之和与后 n 位数字之和相等，则认为这个数字是一个对称整数。
// 返回在 [low, high] 范围内的 对称整数的数目 。

// 方法：直接枚举 但注意题目范围只有两位数或者四位数
class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int res = 0;
            for (int a = low; a <= high; ++a){
                if (a <100 && a % 11 ==0) res++;
                else if (a >= 1000 && a <10000){
                    int left = a / 1000 + (a % 1000) / 100;
                    int right = (a % 100) / 10 + a % 10;
                    if(left == right) res++;
                }
            }
            return res;
        }
    };

    // 时间复杂度：O(high−low).
    // 空间复杂度：O(1).