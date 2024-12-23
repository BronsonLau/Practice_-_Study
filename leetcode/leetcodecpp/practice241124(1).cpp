// 632. 最小区间
// 你有 k 个 非递减排列 的整数列表。找到一个 最小 区间，使得 k 个列表中的每个列表至少有一个数包含在其中。
// 我们定义如果 b-a < d-c 或者在 b-a == d-c 时 a < c，则区间 [a,b] 比 [c,d] 小。

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int rangeLeft = 0, rangeRight = INT_MAX;
        int size = nums.size();
        vector<int> next(size);
        
        auto cmp = [&](const int& u, const int& v) {
            return nums[u][next[u]] > nums[v][next[v]];
        };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        int minValue = 0, maxValue = INT_MIN;
        for (int i = 0; i < size; ++i) {
            pq.emplace(i);
            maxValue = max(maxValue, nums[i][0]);
        }

        while (true) {
            int row = pq.top();
            pq.pop();
            minValue = nums[row][next[row]];
            if (maxValue - minValue < rangeRight - rangeLeft) {
                rangeLeft = minValue;
                rangeRight = maxValue;
            }
            if (next[row] == nums[row].size() - 1) {
                break;
            }
            ++next[row];
            maxValue = max(maxValue, nums[row][next[row]]);
            pq.emplace(row);
        }

        return {rangeLeft, rangeRight};
    }
};

//方法一：贪心 + 最小堆
// 给定 k 个列表，需要找到最小区间，使得每个列表都至少有一个数在该区间中。该问题可以转化为，从 k 个列表中各取一个数，使得这 k 个数中的最大值与最小值的差最小。

// 假设这 k 个数中的最小值是第 i 个列表中的 x，对于任意 j=i，设第 j 个列表中被选为 k 个数之一的数是 y，则为了找到最小区间，y 应该取第 j 个列表中大于等于 x 的最小的数，这是一个贪心的策略。贪心策略的正确性简单证明如下：假设 z 也是第 j 个列表中的数，且 z>y，则有 z−x>y−x，同时包含 x 和 z 的区间一定不会小于同时包含 x 和 y 的区间。因此，其余 k−1 个列表中应该取大于等于 x 的最小的数。

// 由于 k 个列表都是升序排列的，因此对每个列表维护一个指针，通过指针得到列表中的元素，指针右移之后指向的元素一定大于或等于之前的元素。

// 使用最小堆维护 k 个指针指向的元素中的最小值，同时维护堆中元素的最大值。初始时，k 个指针都指向下标 0，最大元素即为所有列表的下标 0 位置的元素中的最大值。每次从堆中取出最小值，根据最大值和最小值计算当前区间，如果当前区间小于最小区间则用当前区间更新最小区间，然后将对应列表的指针右移，将新元素加入堆中，并更新堆中元素的最大值。

// 如果一个列表的指针超出该列表的下标范围，则说明该列表中的所有元素都被遍历过，堆中不会再有该列表中的元素，因此退出循环。

// 时间复杂度：O(nklogk)
// 空间复杂度：O(k)