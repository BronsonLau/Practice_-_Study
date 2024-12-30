// 3219. 切蛋糕的最小总开销 II
// 困难

// 有一个 m x n 大小的矩形蛋糕，需要切成 1 x 1 的小块。

// 给你整数 m ，n 和两个数组：

// horizontalCut 的大小为 m - 1 ，其中 horizontalCut[i] 表示沿着水平线 i 切蛋糕的开销。
// verticalCut 的大小为 n - 1 ，其中 verticalCut[j] 表示沿着垂直线 j 切蛋糕的开销。
// 一次操作中，你可以选择任意不是 1 x 1 大小的矩形蛋糕并执行以下操作之一：

// 沿着水平线 i 切开蛋糕，开销为 horizontalCut[i] 。
// 沿着垂直线 j 切开蛋糕，开销为 verticalCut[j] 。
// 每次操作后，这块蛋糕都被切成两个独立的小蛋糕。

// 每次操作的开销都为最开始对应切割线的开销，并且不会改变。

// 请你返回将蛋糕全部切成 1 x 1 的蛋糕块的 最小 总开销。

class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end());
        sort(verticalCut.begin(), verticalCut.end());
        long long h = 1, v = 1;
        long long res = 0;
        while (!horizontalCut.empty() || !verticalCut.empty()) {
            if (verticalCut.empty() || !horizontalCut.empty() && horizontalCut.back() > verticalCut.back()) {
                res += horizontalCut.back() * h;
                horizontalCut.pop_back();
                v++;
            } else {
                res += verticalCut.back() * v;
                verticalCut.pop_back();
                h++;
            }
        }
        return res;
    }
};

// 方法一：贪心
// 思路

// 我们先尝试按照两种顺序切，第一种顺序是横着切一次，竖着沿着一条线连续切两次，开销是 horizontalCut[i]+2×verticalCut[j]；第二种顺序是竖着切一次，横着沿着一条线连续切两次，开销是 verticalCut[j]+2×horizontalCut[j]。这么一比较，这两种顺序的切法，切出来的一样的，但是开销却有不同。贪心地看，第一刀应该选择开销最大的线来切。因此，我们就提出一个贪心的猜想，将 horizontalCut 和 verticalCut 分别排序，每次切的时候都挑选最大的开销，并切到底。

// 接下来证明，按照这样的顺序，交换相邻两刀，不会使得开销更小。假设当前蛋糕已经沿着水平线切了 p 刀，沿着垂直线切了 q 刀。我们尝试交换接下来两刀：

// 如果接下来两刀都是水平或者垂直，那么交换这两刀对开销不会产生任何影响。
// 如果先是一刀水平，再是一刀垂直，那么开销就是 (q+1)×horizontalCut[i]+(p+2)×verticalCut[j]。如果我们交换这两刀的顺序，那么开销就是 (q+2)×horizontalCut[i]+(p+1)×verticalCut[j]。因为是原来是先切水平，再切垂直，那么会有 horizontalCut[i]≥verticalCut[j]。因此，交换顺序并不会使得开销变小。
// 如果先是一刀垂直，再是一刀水平。相似的论证，交换顺序并不会使得开销变小。
// 因此，按照这样的顺序，交换相邻两刀，不会使得开销更小。而交换任意两刀的顺序，可以通过多次交换相邻两刀的顺序得到。因此，交换任意两刀，不会使得开销更小。


// 复杂度分析
// 时间复杂度：O(m×logm+n×logn)。
// 空间复杂度：O(logm+logn)。