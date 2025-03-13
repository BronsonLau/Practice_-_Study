// 3305. 元音辅音字符串计数 I

// 给你一个字符串 word 和一个 非负 整数 k。
// 返回 word 的 子字符串 中，每个元音字母（'a'、'e'、'i'、'o'、'u'）至少 出现一次，并且 恰好 包含 k 个辅音字母的子字符串的总数。

class Solution {
    public:
        long long countOfSubstrings(string word, int k) {
            set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
            int n = word.size();
            long long res = 0;
            for (int i = 0; i < n; i++) {
                set<char> occur;
                int consonants = 0;
                for (int j = i; j < n; j++) {
                    if (vowels.count(word[j])) {
                        occur.insert(word[j]);
                    } else {
                        consonants++;
                    }
                    if (occur.size() == vowels.size() && consonants == k) {
                        res++;
                    }
                }
            }
            return res;
        }
    };
    
    