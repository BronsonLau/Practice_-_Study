// 632. 最小区间
// 你有 k 个 非递减排列 的整数列表。找到一个 最小 区间，使得 k 个列表中的每个列表至少有一个数包含在其中。
// 我们定义如果 b-a < d-c 或者在 b-a == d-c 时 a < c，则区间 [a,b] 比 [c,d] 小。

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> indices;
        int xMin = INT_MAX, xMax = INT_MIN;
        for (int i = 0; i < n; ++i) {
            for (const int& x: nums[i]) {
                indices[x].push_back(i);
                xMin = min(xMin, x);
                xMax = max(xMax, x);
            }
        }

        vector<int> freq(n);
        int inside = 0;
        int left = xMin, right = xMin - 1;
        int bestLeft = xMin, bestRight = xMax;

        while (right < xMax) {
            ++right;
            if (indices.count(right)) {
                for (const int& x: indices[right]) {
                    ++freq[x];
                    if (freq[x] == 1) {
                        ++inside;
                    }
                }
                while (inside == n) {
                    if (right - left < bestRight - bestLeft) {
                        bestLeft = left;
                        bestRight = right;
                    }
                    if (indices.count(left)) {
                        for (const int& x: indices[left]) {
                            --freq[x];
                            if (freq[x] == 0) {
                                --inside;
                            }
                        }
                    }
                    ++left;
                }
            }
        }

        return {bestLeft, bestRight};
    }
};

// 方法二：哈希表 + 滑动窗口
// 思路

// 在讲这个方法之前我们先思考这样一个问题：有一个序列 A={a 
// 1
// ​
//  ,a 
// 2
// ​
//  ,⋯,a 
// n
// ​
//  } 和一个序列 B={b 
// 1
// ​
//  ,b 
// 2
// ​
//  ,⋯,b 
// m
// ​
//  }，请找出一个 B 中的一个最小的区间，使得在这个区间中 A 序列的每个数字至少出现一次，请注意 A 中的元素可能重复，也就是说如果 A 中有 p 个 u，那么你选择的这个区间中 u 的个数一定不少于 p。没错，这就是我们五月份的一道打卡题：「76. 最小覆盖子串」。官方题解使用了一种滑动窗口的方法，遍历整个 B 序列并用一个哈希表表示当前窗口中的元素：

// 右边界在每次遍历到新元素的时候右移，同时将拓展到的新元素加入哈希表；
// 左边界右移当且仅当当前区间为一个合法的答案区间，即当前窗口内的元素包含 A 中所有的元素，同时将原来左边界指向的元素从哈希表中移除；
// 答案更新当且仅当当前窗口内的元素包含 A 中所有的元素。
// 如果这个地方不理解，可以参考「76. 最小覆盖子串的官方题解」。

// 回到这道题，我们发现这两道题的相似之处在于都要求我们找到某个符合条件的最小区间，我们可以借鉴「76. 最小覆盖子串」的做法：这里序列 {0,1,⋯,k−1} 就是上面描述的 A 序列，即 k 个列表，我们需要在一个 B 序列当中找到一个区间，可以覆盖 A 序列。这里的 B 序列是什么？我们可以用一个哈希映射来表示 B 序列—— B[i] 表示 i 在哪些列表当中出现过，这里哈希映射的键是一个整数，表示列表中的某个数值，哈希映射的值是一个数组，这个数组里的元素代表当前的键出现在哪些列表里。也许文字表述比较抽象，大家可以结合下面这个例子来理解。

// 如果列表集合为：
// 0: [-1, 2, 3]
// 1: [1]
// 2: [1, 2]
// 3: [1, 1, 3]
// 那么可以得到这样一个哈希映射
// -1: [0]
//  1: [1, 2, 3, 3]
//  2: [0, 2]
//  3: [0, 3]
// 我们得到的这个哈希映射就是这里的 B 序列。我们要做的就是在 B 序列上使用两个指针维护一个滑动窗口，并用一个哈希表维护当前窗口中已经包含了哪些列表中的元素，记录它们的索引。遍历 B 序列的每一个元素：

// 指向窗口右边界的指针右移当且仅当每次遍历到新的元素，并将这个新的元素对应的值数组中的每一个数加入到哈希表中；
// 指向窗口左边界的指针右移当且仅当当前区间内的元素包含 A 中所有的元素，同时将原来左边界对应的值数组的元素们从哈希表中移除；
// 答案更新当且仅当当前窗口内的元素包含 A 中所有的元素。

// 时间复杂度：O(nk+∣V∣)
// 空间复杂度：O(nk)
