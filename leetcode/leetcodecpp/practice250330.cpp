// 2109. 向字符串添加空格

// 给你一个下标从 0 开始的字符串 s ，以及一个下标从 0 开始的整数数组 spaces 。

// 数组 spaces 描述原字符串中需要添加空格的下标。每个空格都应该插入到给定索引处的字符值 之前 。

// 例如，s = "EnjoyYourCoffee" 且 spaces = [5, 9] ，那么我们需要在 'Y' 和 'C' 之前添加空格，这两个字符分别位于下标 5 和下标 9 。因此，最终得到 "Enjoy Your Coffee" 。
// 请你添加空格，并返回修改后的字符串。

class Solution {
    public:
        string addSpaces(string s, vector<int>& spaces) {
            int n = s.size();
            string ans;
            ans.reserve(n + spaces.size());
            
            int ptr = 0;
            for (int i = 0; i < n; ++i) {
                if (ptr < spaces.size() && spaces[ptr] == i) {
                    ans.push_back(' ');
                    ++ptr;
                }
                ans.push_back(s[i]);
            }
            return ans;
        }
    };
    

// 双指针法

// 时间复杂度：O(n+m)，其中 n 是字符串 s 的长度，m 是数组 spaces 的长度。
// 空间复杂度：O(1) 或 O(n+m)，取决于使用的语言中字符串是否可以修改。

  