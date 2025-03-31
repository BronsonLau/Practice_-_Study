// 2278. 字母在字符串中的百分比
// 题目难度 Easy
// 给你一个字符串 s 和一个字符 letter ，返回在 s 中等于 letter 字符所占的 百分比 ，向下取整到最接近的百分比。

class Solution {
    public:
        int percentageLetter(string s, char letter) {
            int n  = s.size();
            int count = 0;
            for (char i:s){
                if (i == letter){
                    count ++;
                }
            }
            return count*100 / n;
        }
    };

// 时间复杂度：O(n)，其中 n 是字符串 s 的长度。
// 空间复杂度：O(1)。