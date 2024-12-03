// 2056. 棋盘上有效移动组合的数目
// 有一个 8 x 8 的棋盘，它包含 n 个棋子（棋子包括车，后和象三种）。给你一个长度为 n 的字符串数组 pieces ，其中 pieces[i] 表示第 i 个棋子的类型（车，后或象）。除此以外，还给你一个长度为 n 的二维整数数组 positions ，其中 positions[i] = [ri, ci] 表示第 i 个棋子现在在棋盘上的位置为 (ri, ci) ，棋盘下标从 1 开始。

// 棋盘上每个棋子都可以移动 至多一次 。每个棋子的移动中，首先选择移动的 方向 ，然后选择 移动的步数 ，同时你要确保移动过程中棋子不能移到棋盘以外的地方。棋子需按照以下规则移动：

// 车可以 水平或者竖直 从 (r, c) 沿着方向 (r+1, c)，(r-1, c)，(r, c+1) 或者 (r, c-1) 移动。
// 后可以 水平竖直或者斜对角 从 (r, c) 沿着方向 (r+1, c)，(r-1, c)，(r, c+1)，(r, c-1)，(r+1, c+1)，(r+1, c-1)，(r-1, c+1)，(r-1, c-1) 移动。
// 象可以 斜对角 从 (r, c) 沿着方向 (r+1, c+1)，(r+1, c-1)，(r-1, c+1)，(r-1, c-1) 移动。
// 移动组合 包含所有棋子的 移动 。每一秒，每个棋子都沿着它们选择的方向往前移动 一步 ，直到它们到达目标位置。所有棋子从时刻 0 开始移动。如果在某个时刻，两个或者更多棋子占据了同一个格子，那么这个移动组合 不有效 。

// 请你返回 有效 移动组合的数目。

// 注意：
// 初始时，不会有两个棋子 在 同一个位置 。
// 有可能在一个移动组合中，有棋子不移动。
// 如果两个棋子 直接相邻 且两个棋子下一秒要互相占据对方的位置，可以将它们在同一秒内 交换位置 。

class Movement {
public:
    Movement(int start_x, int start_y, int end_x, int end_y, int dx, int dy)
        : start_x_(start_x), start_y_(start_y), end_x_(end_x), end_y_(end_y), 
          dx_(dx), dy_(dy), cur_x_(start_x), cur_y_(start_y)
    {}

    void reset() {
        cur_x_ = start_x_;
        cur_y_ = start_y_;
    }

    bool stopped() {
        return cur_x_ == end_x_ && cur_y_ == end_y_;
    }

    void advance() {
        if (!stopped()) {
            cur_x_ += dx_;
            cur_y_ += dy_;
        }
    }

    bool cross(Movement& oth) {
        // 每次判断是否相遇时需要重置 cur
        reset();
        oth.reset();
        while (!stopped() || !oth.stopped()) {
            advance();
            oth.advance();
            if (cur_x_ == oth.cur_x_ && cur_y_ == oth.cur_y_) {
                return true;
            }
        }
        return false;
    }

public:
    const int start_x_;
    const int start_y_;
    const int end_x_;
    const int end_y_;
    const int dx_;
    const int dy_;
    int cur_x_;
    int cur_y_;
};

class Solution {
public:
    int countCombinations(vector<string>& pieces, vector<vector<int>>& positions) {
        vector<vector<int>> rook_dire_ = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> bishop_dire_ = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        vector<vector<int>> queen_dire_ = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        int n = pieces.size();
        int res = 0;
        vector<Movement> stk;

        // 判断第 u 个棋子是否之前的棋子在移动过程中相遇
        auto check = [&](int u) {
            for (int v = 0; v < u; v++) {
                if (stk[u].cross(stk[v])) {
                    return false;
                }
            }
            return true;
        };

        function<void(int)> dfs = [&](int u) {
            if (u == n) {
                res++;
                return;
            }
            vector<vector<int>> dire;
            if (pieces[u] == "rook") {
                dire = rook_dire_;
            } else if (pieces[u] == "queen") {
                dire = queen_dire_;
            } else if (pieces[u] == "bishop") {
                dire = bishop_dire_;
            }

            // 处理第 u 个棋子原地不动的情况
            stk.push_back(Movement(positions[u][0], positions[u][1], positions[u][0], positions[u][1], 0, 0));
            if (check(u)) {
                dfs(u + 1);
            }
            stk.pop_back();

            // 枚举第 u 个棋子在所有方向、所有步数的情况
            for (int i = 0; i < dire.size(); i++) {
                for (int j = 1; j < 8; j++) {
                    int x = positions[u][0] + dire[i][0] * j;
                    int y = positions[u][1] + dire[i][1] * j;
                    if (x < 1 || x > 8 || y < 1 || y > 8) {
                        break;
                    }
                    stk.push_back(Movement(positions[u][0], positions[u][1], x, y, dire[i][0], dire[i][1]));
                    if (check(u)) {
                        dfs(u + 1);
                    }
                    stk.pop_back();
                }
            }
        };
        dfs(0);
        return res;
    }
};

/*官方题解*/
// 思路：
// 本题是一个搜索问题，我们可以使用深度优先搜索来解决。我们可以枚举每个棋子的移动方式，然后递归地搜索所有的移动组合。
// 为了判断两个棋子是否在移动过程中相遇，我们可以使用两个 Movement 类来表示两个棋子的移动过程。在每次判断是否相遇时，我们需要重置两个 Movement 类的状态，然后模拟两个棋子的移动过程，直到两个棋子相遇或者都停止移动。

// 时间复杂度：O(n^2*m^n)，其中 n 为棋子数量，m 是棋子移动方案数量的最大值。
// 空间复杂度：O(n)。