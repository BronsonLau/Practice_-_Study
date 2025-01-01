// 729. 我的日程安排表 I
// 中等

// 实现一个 MyCalendar 类来存放你的日程安排。如果要添加的日程安排不会造成 重复预订 ，则可以存储这个新的日程安排。

// 当两个日程安排有一些时间上的交叉时（例如两个日程安排都在同一时间内），就会产生 重复预订 。

// 日程可以用一对整数 startTime 和 endTime 表示，这里的时间是半开区间，即 [startTime, endTime), 实数 x 的范围为，  startTime <= x < endTime 。

// 实现 MyCalendar 类：

// MyCalendar() 初始化日历对象。
// boolean book(int startTime, int endTime) 如果可以将日程安排成功添加到日历中而不会导致重复预订，返回 true 。否则，返回 false 并且不要将该日程安排添加到日历中。

class MyCalendar {
    set<pair<int, int>> booked;

public:
    bool book(int start, int end) {
        auto it = booked.lower_bound({end, 0});
        if (it == booked.begin() || (--it)->second <= start) {
            booked.emplace(start, end);
            return true;
        }
        return false;
    }
};

// 方法二：二分查找
// 如果我们按时间顺序维护日程安排，则可以通过二分查找日程安排的情况来检查新日程安排是否可以预订，若可以预订则在排序结构中更新插入日程安排。

// 需要一个数据结构能够保持元素排序和支持快速插入，可以用 TreeSet 来构建。对于给定的区间 [start,end)，我们每次查找起点大于等于 end 的第一个区间 [l 
// 1
// ​
//  ,r 
// 1
// ​
//  )，同时紧挨着 [l 
// 1
// ​
//  ,r 
// 1
// ​
//  ) 的前一个区间为 [l 
// 2
// ​
//  ,r 
// 2
// ​
//  )，此时如果满足 r 
// 2
// ​
//  ≤start<end≤l 
// 1
// ​
//  ，则该区间可以预订。

// 复杂度分析
// 时间复杂度：O(nlogn), 其中 n 表示日程安排的数量。由于每次在进行预订时，都需要进行二分查找，需要的时间为 O(logn)。
// 空间复杂度：O(n)，其中 n 表示日程安排的数量。需要保存所有已经预订的行程。

