// 1328. 破坏回文串

// 给你一个由小写英文字母组成的回文字符串 palindrome ，请你将其中 一个 字符用任意小写英文字母替换，使得结果字符串的字典序最小 ，且不是回文串。
// 请你返回结果字符串。如果无法做到，则返回一个空串。

class Solution {
    public:
        string breakPalindrome(string palindrome) {
            int n = palindrome.size();
            if (n == 1) return "";
            for (int i = 0; i * 2 + 1 < n; i++){
                if(palindrome[i] != 'a'){ // 思路简单 变‘a’即可
                    palindrome[i] = 'a';
                    return palindrome;
                }
            }
            palindrome.back()++; // 将字符串尾部的字符+1变为b
            return palindrome;
        }
    };

// 时间复杂度：O(n)
// 空间复杂度：O(1)