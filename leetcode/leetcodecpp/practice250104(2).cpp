// 732. 我的日程安排表 III
// 困难

// 当 k 个日程存在一些非空交集时（即, k 个日程包含了一些相同时间），就会产生 k 次预订。

// 给你一些日程安排 [startTime, endTime) ，请你在每个日程安排添加后，返回一个整数 k ，表示所有先前日程安排会产生的最大 k 次预订。

// 实现一个 MyCalendarThree 类来存放你的日程安排，你可以一直添加新的日程安排。

// MyCalendarThree() 初始化对象。
// int book(int startTime, int endTime) 返回一个整数 k ，表示日历中存在的 k 次预订的最大值。

class MyCalendarThree {
public:
    unordered_map<int, pair<int, int>> tree;

    MyCalendarThree() {

    }
    
    void update(int start, int end, int l, int r, int idx) {
        if (r < start || end < l) {
            return;
        } 
        if (start <= l && r <= end) {
            tree[idx].first++;
            tree[idx].second++;
        } else {
            int mid = (l + r) >> 1;
            update(start, end, l, mid, 2 * idx);
            update(start, end, mid + 1, r, 2 * idx + 1);
            tree[idx].first = tree[idx].second + max(tree[2 * idx].first, tree[2 * idx + 1].first);
        }
    }

    int book(int start, int end) {            
        update(start, end - 1, 0, 1e9, 1);
        return tree[1].first;
    }
};

// 方法二：线段树
// 思路与算法

// 利用线段树，假设我们开辟了数组 arr[0,⋯,10^9]，初始时每个元素的值都为 0，对于每次行程预定的区间 [start,end) ，则我们将区间中的元素 arr[start,⋯,end−1] 中的每个元素加 1，
// 最终只需要求出数组 arr 的最大元素即可。实际我们不必实际开辟数组 arr，可采用动态线段树，懒标记 lazy 标记区间 [l,r] 进行累加的次数，tree 记录区间 [l,r] 的最大值，最终返回区间 [0,10^9] 中的最大元素即可。


// 复杂度分析
// 时间复杂度：O(nlogC)，其中 n 为日程安排的数量。由于使用了线段树查询，线段树的最大深度为 logC，每次最多会查询 logC 个节点，每次求最大的预定需的时间复杂度为 O(logC+logC)，因此时间复杂度为 O(nlogC)，在此 C 取固定值即为 10^9 。
// 空间复杂度：O(nlogC)，其中 n 为日程安排的数量。由于该解法采用的为动态线段树，线段树的最大深度为 logC，每次预定最多会在线段树上增加 logC 个节点，因此空间复杂度为 O(nlogC)，在此 C 取固定值即为 10^9。
。

