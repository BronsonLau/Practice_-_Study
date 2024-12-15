// 1847. 最近的房间
// 困难

// 一个酒店里有 n 个房间，这些房间用二维整数数组 rooms 表示，其中 rooms[i] = [roomIdi, sizei] 表示有一个房间号为 roomIdi 的房间且它的面积为 sizei 。每一个房间号 roomIdi 保证是 独一无二 的。

// 同时给你 k 个查询，用二维数组 queries 表示，其中 queries[j] = [preferredj, minSizej] 。第 j 个查询的答案是满足如下条件的房间 id ：

// 房间的面积 至少 为 minSizej ，且
// abs(id - preferredj) 的值 最小 ，其中 abs(x) 是 x 的绝对值。
// 如果差的绝对值有 相等 的，选择 最小 的 id 。如果 没有满足条件的房间 ，答案为 -1 。

// 请你返回长度为 k 的数组 answer ，其中 answer[j] 为第 j 个查询的结果。

struct Event {
    // 事件的类型，0 表示房间，1 表示询问
    int type;
    // 房间的 size 或者询问的 minSize
    int size;
    // 房间的 roomId 或者询问的 preferred
    int id;
    // 房间在数组 room 中的原始编号或者询问在数组 queries 中的原始编号
    int origin;
    
    Event(int _type, int _size, int _id, int _origin): type(_type), size(_size), id(_id), origin(_origin) {}
    
    // 自定义比较函数，按照事件的 size 降序排序
    // 如果 size 相同，优先考虑房间
    bool operator< (const Event& that) const {
        return size > that.size || (size == that.size && type < that.type);
    }
};

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int m = rooms.size();
        int n = queries.size();
        
        vector<Event> events;
        for (int i = 0; i < m; ++i) {
            // 房间事件
            events.emplace_back(0, rooms[i][1], rooms[i][0], i);
        }
        for (int i = 0; i < n; ++i) {
            // 询问事件
            events.emplace_back(1, queries[i][1], queries[i][0], i);
        }

        sort(events.begin(), events.end());
        vector<int> ans(n, -1);
        // 存储房间 roomId 的有序集合
        set<int> valid;
        for (const auto& event: events) {
            if (event.type == 0) {
                // 房间事件，将 roomId 加入有序集合
                valid.insert(event.id);
            }
            else {
                // 询问事件
                int dist = INT_MAX;
                // 查找最小的大于等于 preferred 的元素
                auto it = valid.lower_bound(event.id);
                if (it != valid.end() && *it - event.id < dist) {
                    dist = *it - event.id;
                    ans[event.origin] = *it;
                }
                if (it != valid.begin()) {
                    // 查找最大的严格小于 preferred 的元素
                    it = prev(it);
                    if (event.id - *it <= dist) {
                        dist = event.id - *it;
                        ans[event.origin] = *it;
                    }
                }
            }
        }
        
        return ans;
    }
};

// 方法一：离线算法
// 提示 1

// 如果我们可以将给定的房间和询问重新排序，那么是否可以使得问题更加容易解决？

// 提示 2

// 我们可以将房间以及询问都看成一个「事件」，如果我们将这些「事件」按照大小（房间的 size 或者询问的 minSize）进行降序排序，那么：

// 如果我们遇到一个表示房间的「事件」，那么可以将该房间的 roomId 加入某一「数据结构」中；
// 如果我们遇到一个表示询问的「事件」，那么需要在「数据结构」中寻找与 preferred 最接近的 roomId。
// 提示 3

// 你能想出一种合适的「数据结构」吗？

// 思路与算法

// 我们使用「有序集合」作为提示中的「数据结构」。

// 根据提示 2，我们将每一个房间以及询问对应一个「事件」，放入数组中进行降序排序。随后我们遍历这些「事件」：

// 如果我们遇到一个表示房间的「事件」，那么将该该房间的 roomId 加入「有序集合」中；
// 如果我们遇到一个表示询问的「事件」，那么答案即为「有序集合」中与询问的 preferred 最接近的那个 roomId。在大部分语言的「有序集合」的 API 中，提供了例如「在有序集合中查找最小的大于等于 x 的元素」或者「在有序集合中查找最小的严格大于 x 的元素」，我们可以利用这些 API 找出「有序集合」中与 preferred 最接近的两个元素，其中一个小于 preferred，另一个大于等于 preferred。通过比较这两个元素，我们即可得到该询问对应的答案。
// 细节

// 如果不同类型的「事件」的位置相同，那么我们应当按照先处理表示房间的「事件」，再处理表示询问的「事件」，这是因为房间的 size 只要大于等于询问的 minSize 就是满足要求的。



// 时间复杂度：O((n+q)log(n+q))，其中 n 是数组 rooms 的长度，q 是数组 queries 的长度。「事件」的数量为 n+q=O(n+q)，因此需要 O((n+q)log(n+q)) 的时间进行排序。在这之后，我们需要 O(n+q) 的时间对事件进行遍历，而对有序集合进行操作的单次时间复杂度为 O(logn)，总时间复杂度为 O((n+q)logn)，在渐进意义下小于前者，可以忽略。

// 空间复杂度：O(n+q)。我们需要 O(n+q) 的空间存储「事件」，以及 O(n) 的空间分配给有序集合，因此总空间复杂度为 O(n+q)。

