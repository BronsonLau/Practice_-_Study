// 729. 我的日程安排表 I
// 中等

// 实现一个 MyCalendar 类来存放你的日程安排。如果要添加的日程安排不会造成 重复预订 ，则可以存储这个新的日程安排。

// 当两个日程安排有一些时间上的交叉时（例如两个日程安排都在同一时间内），就会产生 重复预订 。

// 日程可以用一对整数 startTime 和 endTime 表示，这里的时间是半开区间，即 [startTime, endTime), 实数 x 的范围为，  startTime <= x < endTime 。

// 实现 MyCalendar 类：

// MyCalendar() 初始化日历对象。
// boolean book(int startTime, int endTime) 如果可以将日程安排成功添加到日历中而不会导致重复预订，返回 true 。否则，返回 false 并且不要将该日程安排添加到日历中。

class MyCalendar {
    vector<pair<int, int>> booked;

public:
    bool book(int start, int end) {
        for (auto &[l, r] : booked) {
            if (l < end && start < r) {
                return false;
            }
        }
        booked.emplace_back(start, end);
        return true;
    }
};

// 方法一：直接遍历
// 我们记录下所有已经预订的课程安排区间，当我们预订新的区间 [start,end) 时，此时检查当前已经预订的每个日程安排是否与新日程安排冲突。若不冲突，则可以添加新的日程安排。

// 对于两个区间 [s 
// 1
// ​
//  ,e 
// 1
// ​
//  ) 和 [s 
// 2
// ​
//  ,e 
// 2
// ​
//  )，如果二者没有交集，则此时应当满足 s 
// 1
// ​
//  ≥e 
// 2
// ​
//   或者 s 
// 2
// ​
//  ≥e 
// 1
// ​
//  ，这就意味着如果满足 s 
// 1
// ​
//  <e 
// 2
// ​
//   并且 s 
// 2
// ​
//  <e 
// 1
// ​
//  ，则两者会产生交集。

// 复杂度分析

// 时间复杂度：O(n 
// 2
//  ), 其中 n 表示日程安排的数量。由于每次在进行预订时，都需要遍历所有已经预订的行程安排。
// 空间复杂度：O(n)，其中 n 表示日程安排的数量。需要保存所有已经预订的行程。
