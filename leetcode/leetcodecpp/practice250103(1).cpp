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
        for (auto &[l, r] : overlaps) {
            if (l < end && start < r) {
                return false;
            }
        }
        for (auto &[l, r] : booked) {
            if (l < end && start < r) {
                overlaps.emplace_back(max(l, start), min(r, end));
            }
        }
        booked.emplace_back(start, end);
        return true;
    }
private:
    vector<pair<int, int>> booked;
    vector<pair<int, int>> overlaps;
};


//方法1：直接遍历
// 记录下所有已经预定的课程安排区间与已经预定过两次的课程安排区间，当我们预定新的区间 [start,end) 时，此时检查当前已经预定过两次的每个日程安排是否与新日程安排冲突。若不冲突，则可以添加新的日程安排。

// 对于两个区间 [s 
// 1
// ​
//  ，e 
// 1
// ​
//  ) 和 [s 
// 2
// ​
//  ，e 
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
//   时，则两者会产生差集。
// 首先检测新加入的区间 [start,end) 是否与已经预定过两次的区间有交集，如果没有冲突，则将新加入的区间与已经预定的区间进行检查，求出新增的预定两次的区间。对于两个区间 [s 
// 1
// ​
//  ，e 
// 1
// ​
//  ) 和 [s 
// 2
// ​
//  ，e 
// 2
// ​
//  )，则他们之间的交集为 [max(s 
// 1
// ​
//  ,s 
// 2
// ​
//  ),min(e 
// 1
// ​
//  ,e 
// 2
// ​
//  ))。

// 复杂度分析：
// 时间复杂度：O(n ^ 2), 其中 n 表示日程安排的数量。由于每次在进行预定时，都需要遍历所有已经预定的行程安排。
// 空间复杂度：O(n)，其中 n 表示日程安排的数量。需要保存所有已经预定的行程。

