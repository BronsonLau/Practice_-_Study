// 732. 我的日程安排表 III
// 困难

// 当 k 个日程存在一些非空交集时（即, k 个日程包含了一些相同时间），就会产生 k 次预订。

// 给你一些日程安排 [startTime, endTime) ，请你在每个日程安排添加后，返回一个整数 k ，表示所有先前日程安排会产生的最大 k 次预订。

// 实现一个 MyCalendarThree 类来存放你的日程安排，你可以一直添加新的日程安排。

// MyCalendarThree() 初始化对象。
// int book(int startTime, int endTime) 返回一个整数 k ，表示日历中存在的 k 次预订的最大值。

class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        int ans = 0;
        int maxBook = 0;
        cnt[start]++;
        cnt[end]--;
        for (auto &[_, freq] : cnt) {
            maxBook += freq;
            ans = max(maxBook, ans);
        }
        return ans;
    }
private:
    map<int, int> cnt;
};


// 方法一：差分数组
// 思路与算法:
// 可以参考「731. 我的日程安排表 II」的解法二，我们可以采用同样的思路即可。利用差分数组的思想，每当我们预定一个新的日程安排 [start,end)，在 start 计数 cnt[start] 加 1，表示从 start 预定的数目加 1；从 end 计数 cnt[end] 减 1，表示从 end 开始预定的数目减 1。此时以起点 x 开始的预定的数目 book 
// x ​ =∑ y≤x
// ​
//  cnt[y]，我们对计数进行累加依次求出最大的预定数目即可。由于本题中 start,end 数量较大，我们利用 TreeMap 计数即可。


// 复杂度分析
// 时间复杂度：O(n^2)，其中 n 为日程安排的数量。每次求的最大的预定需要遍历所有的日程安排。
// 空间复杂度：O(n)，其中 n 为日程安排的数量。需要空间存储所有的日程安排计数，需要的空间为 O(n)。

