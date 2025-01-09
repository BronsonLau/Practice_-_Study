// 3297. 统计重新排列后包含另一个字符串的子字符串数目 I
// 中等

// 给你两个字符串 word1 和 word2 。
// 如果一个字符串 x 重新排列后，word2 是重排字符串的 前缀，那么我们称字符串 x 是 合法的 。

// 请你返回 word1 中 合法 子字符串的数目。

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        vector<int> diff(26, 0);
        for (auto c : word2) {
            diff[c - 'a']--;
        }

        long long res = 0;
        int cnt = count_if(diff.begin(), diff.end(), [](int c) { return c < 0; });
        auto update = [&](int c, int add) {
            diff[c] += add;
            if (add == 1 && diff[c] == 0) {
                // 表明 diff[c] 由 -1 变为 0
                cnt--;
            } else if (add == -1 && diff[c] == -1) {
                // 表明 diff[c] 由 0 变为 -1
                cnt++;
            }
        };

        for (int l = 0, r = 0; l < word1.size(); l++) {
            while (r < word1.size() && cnt > 0) {
                update(word1[r] - 'a', 1);
                r++;
            }
            if (cnt == 0) {
                res += word1.size() - r + 1;
            }
            update(word1[l] - 'a', -1);
        }
        return res;
    }
};

// 方法二：滑动窗口
// 思路与算法

// 每次消耗 O(Clogn) 的时间去找 r 太过奢侈，我们需要发现一些性质来加速。注意到每次找到 l 匹配的 r 后，将 l 增加 1，区间内的字符减少，相应的 r 势必会增加。因此得到结论：随着 l 的增加，r 也会增加，我们可以使用滑动窗口来避免二分过程中的重复查找。
// 具体来说，我们用哈希表维护当前窗口内每种字符的出现次数，初始时窗口长度为 0，每次我们向右移动 r，并将字符加入哈希表，直到每种字符的出现次数都大于 word2 中的出现次数，此时将答案累加 n−r+1。接着我们要计算 l+1 作为左边界的情况，将 l 处的字符移除哈希表，并继续向右移动 r，重复前面的过程即可。
// 我们在上面采用了 O(C) 的时间复杂度判断滑动窗口内每种字符的出现次数是否都大于 word2 中的出现次数，其实还可以进一步优化。我们将维护的对象更改为滑动窗口内每种字符出现次数与 word2 中每种字符出现次数的差值，当所有差值都大于等于 0 则表示合法。但到这一步还没有与之前的方法拉开差距，需要再维护一个变量 cnt 表示差值小于 0 的字符种类数，当 cnt 等于 0 则表示合法。在滑动窗口移动时，可以仅消耗 O(1) 的时间来维护 cnt，这样一来就降低了时间复杂度。


// 复杂度分析
// 时间复杂度：O(n+m)，其中 n 是 word1 的长度，m 是 word2 的长度。
// 空间复杂度：O(C)，其中 C 是字符种类数，本题中等于 26。
