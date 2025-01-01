// 729. 我的日程安排表 I
// 中等

// 实现一个 MyCalendar 类来存放你的日程安排。如果要添加的日程安排不会造成 重复预订 ，则可以存储这个新的日程安排。

// 当两个日程安排有一些时间上的交叉时（例如两个日程安排都在同一时间内），就会产生 重复预订 。

// 日程可以用一对整数 startTime 和 endTime 表示，这里的时间是半开区间，即 [startTime, endTime), 实数 x 的范围为，  startTime <= x < endTime 。

// 实现 MyCalendar 类：

// MyCalendar() 初始化日历对象。
// boolean book(int startTime, int endTime) 如果可以将日程安排成功添加到日历中而不会导致重复预订，返回 true 。否则，返回 false 并且不要将该日程安排添加到日历中。

class MyCalendar {
    unordered_set<int> tree, lazy;

public:
    bool query(int start, int end, int l, int r, int idx) {
        if (r < start || end < l) {
            return false;
        }
        /* 如果该区间已被预订，则直接返回 */
        if (lazy.count(idx)) {
            return true;
        }
        if (start <= l && r <= end) {
            return tree.count(idx);
        }
        int mid = (l + r) >> 1;
        return query(start, end, l, mid, 2 * idx) ||
               query(start, end, mid + 1, r, 2 * idx + 1);
    }

    void update(int start, int end, int l, int r, int idx) {
        if (r < start || end < l) {
            return;
        }
        if (start <= l && r <= end) {
            tree.emplace(idx);
            lazy.emplace(idx);
        } else {
            int mid = (l + r) >> 1;
            update(start, end, l, mid, 2 * idx);
            update(start, end, mid + 1, r, 2 * idx + 1);
            tree.emplace(idx);
            if (lazy.count(2 * idx) && lazy.count(2 * idx + 1)) {
                lazy.emplace(idx);
            }
        }
    }

    bool book(int start, int end) {
        if (query(start, end - 1, 0, 1e9, 1)) {
            return false;
        }
        update(start, end - 1, 0, 1e9, 1);
        return true;
    }
};

// 方法三：线段树
// 利用线段树，假设我们开辟了数组 arr[0,⋯,10 
// 9
//  ]，初始时每个元素的值都为 0，对于每次行程预订的区间 [start,end) ，则我们将区间中的元素 arr[start,⋯,end−1] 中的每个元素都标记为 1，每次调用 book 时，我们只需要检测 arr[start,⋯,end−1] 区间内是否有元素被标记为 1。实际我们不必实际开辟数组 arr，可采用动态线段树，懒标记 lazy 标记区间 [l,r] 已经被预订，tree 记录区间 [l,r] 的是否存在标记为 1 的元素。

// 每次进行 book 操作时，首先判断区间 [start,⋯,end−1] 是否存在元素被标记，如果存在被标记为 1 的元素，则表明该区间不可预订；否则，则将可以预订。预订完成后，将 arr[start,⋯,end−1] 进行标记为 1，并同时更新线段树。

// 复杂度分析
// 时间复杂度：O(nlogC)，其中 n 为日程安排的数量。由于使用了线段树查询，线段树的最大深度为 logC，每次最多会查询 logC 个节点，每次求最大的预订需的时间复杂度为 O(logC+logC)，因此时间复杂度为 O(nlogC)，在此 C 取固定值 10 
// 9
//  。
// 空间复杂度：O(nlogC)，其中 n 为日程安排的数量。由于该解法采用的为动态线段树，线段树的最大深度为 logC，每次预订最多会在线段树上增加 logC 个节点，因此空间复杂度为 O(nlogC)，在此 C 取固定值 10 
// 9
//  。

