// 731. 我的日程安排表 II
// 中等

// 实现一个程序来存放你的日程安排。如果要添加的时间内不会导致三重预订时，则可以存储这个新的日程安排。

// 当三个日程安排有一些时间上的交叉时（例如三个日程安排都在同一时间内），就会产生 三重预订。

// 事件能够用一对整数 startTime 和 endTime 表示，在一个半开区间的时间 [startTime, endTime) 上预定。实数 x 的范围为  startTime <= x < endTime。

// 实现 MyCalendarTwo 类：

// MyCalendarTwo() 初始化日历对象。
// boolean book(int startTime, int endTime) 如果可以将日程安排成功添加到日历中而不会导致三重预订，返回 true。否则，返回 false 并且不要将该日程安排添加到日历中。

class MyCalendarTwo {
public:
    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        int ans = 0;
        int maxBook = 0;
        cnt[start]++;
        cnt[end]--;
        for (auto &[_, freq] : cnt) {
            maxBook += freq;
            ans = max(maxBook, ans);
            if (maxBook > 2) {
                cnt[start]--;
                cnt[end]++;
                return false;
            }
        }
        return true;
    }
private:
    map<int, int> cnt;
};


// 方法2：差分数组
// 利用差分数组的思想，每当我们预定一个新的日程安排 [start,end)，在 start 计数 cnt[start] 加 1，表示从 start 预定的数目加 1；从 end 计数 cnt[end] 减 1，表示从 end 开始预定的数目减 1。此时以起点 x 开始的预定的数目 book 
// x
// ​
//  =∑ 
// y≤x
// ​
//  cnt[y]，当我们将 [start,end) 加入后，如果发现存在区间的预定数目大于 2 时，此时为非法应去除新加入的区间 [start,end)。由于本题中 start,end 数量较大，我们利用 TreeMap 计数即可。


// 复杂度分析
// 时间复杂度：O(n^ 2)，其中 n 为日程安排的数量。每次求的最大的预定需要遍历所有的日程安排。
// 空间复杂度：O(n)，其中 n 为日程安排的数量。需要空间存储所有的日程安排计数，需要的空间为 O(n)。

