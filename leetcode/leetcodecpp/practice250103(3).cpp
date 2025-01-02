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

    void update(int start, int end, int val, int l, int r, int idx) {
        if (r < start || end < l) {
            return;
        } 
        if (start <= l && r <= end) {
            tree[idx].first += val;
            tree[idx].second += val;
        } else {
            int mid = (l + r) >> 1;
            update(start, end, val, l, mid, 2 * idx);
            update(start, end, val, mid + 1, r, 2 * idx + 1);
            tree[idx].first = tree[idx].second + max(tree[2 * idx].first, tree[2 * idx + 1].first);
        }
    }

    bool book(int start, int end) {            
        update(start, end - 1, 1, 0, 1e9, 1);
        if (tree[1].first > 2) {
            update(start, end - 1, -1, 0, 1e9, 1);
            return false;
        }
        return true;
    }
private:
    unordered_map<int, pair<int, int>> tree;
};



// 方法3：线段树
// 利用线段树，假设我们开辟了数组 arr[0,⋯,10 
// 9
//  ]，初始时每个元素的值都为 0，对于每次行程预定的区间 [start,end) ，则我们将区间中的元素 arr[start,⋯,end−1] 中的每个元素加 1，如果数组 arr 的最大元素大于 2 时，此时则出现某个区间被安排了 2 次上，此时返回 false，同时将数组区间 arr[start,⋯,end−1] 进行减 1 即可恢复。实际我们不必实际开辟数组 arr，可采用动态线段树，懒标记 lazy 标记区间 [l,r] 进行累加的次数，tree 记录区间 [l,r] 的最大值，每次动态更新线段树即可。


// 复杂度分析
// 时间复杂度：O(nlogC)，其中 n 为日程安排的数量。由于使用了线段树查询，线段树的最大深度为 logC, 每次最多会查询 logC 个节点，每次求最大的预定需的时间复杂度为 O(logC+logC)，因此时间复杂度为 O(nlogC)，在此 C 取固定值即为 10 
// 9。
// 空间复杂度：O(nlogC)，其中 n 为日程安排的数量。由于该解法采用的为动态线段树，线段树的最大深度为 logC，每次预定最多会在线段树上增加 logC 个节点，因此空间复杂度为 O(nlogC)，在此 C 取固定值即为 10 ^9。

