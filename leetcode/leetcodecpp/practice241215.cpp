// 1338. 数组大小减半
// 中等

// 给你一个整数数组 arr。你可以从中选出一个整数集合，并删除这些整数在数组中的每次出现。

// 返回 至少 能删除数组中的一半整数的整数集合的最小大小。

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int num: arr) {
            ++freq[num];
        }
        vector<int> occ;
        for (auto& [k, v]: freq) {
            occ.push_back(v);
        }
        sort(occ.begin(), occ.end(), greater<int>());
        int cnt = 0, ans = 0;
        for (int c: occ) {
            cnt += c;
            ans += 1;
            if (cnt * 2 >= arr.size()) {
                break;
            }
        }
        return ans;
    }
};

// 思路：
// 统计每个数字出现的次数，然后按照出现次数从大到小排序，然后从大到小累加，直到累加的数字个数大于等于数组长度的一半，返回累加的数字个数。

// 时间复杂度分析：O(nlogn)，其中 n 是数组 arr 的长度。统计每个数字出现的次数需要 O(n) 的时间复杂度，排序需要 O(nlogn) 的时间复杂度，累加需要 O(n) 的时间复杂度。
// 空间复杂度分析：O(n)，其中 n 是数组 arr 的长度。需要 O(n) 的空间存储每个数字出现的次数。