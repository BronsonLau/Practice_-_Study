// 3238. 求出胜利玩家的数目

// 给你一个整数 n ，表示在一个游戏中的玩家数目。同时给你一个二维整数数组 pick ，其中 pick[i] = [xi, yi] 表示玩家 xi 获得了一个颜色为 yi 的球。

// 如果玩家 i 获得的球中任何一种颜色球的数目 严格大于 i 个，那么我们说玩家 i 是胜利玩家。换句话说：

// 如果玩家 0 获得了任何的球，那么玩家 0 是胜利玩家。
// 如果玩家 1 获得了至少 2 个相同颜色的球，那么玩家 1 是胜利玩家。
// ...
// 如果玩家 i 获得了至少 i + 1 个相同颜色的球，那么玩家 i 是胜利玩家。
// 请你返回游戏中 胜利玩家 的数目。

// 注意，可能有多个玩家是胜利玩家。

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
    vector<vector<int>> cnt(n, vector<int>(11));
    for (auto &p : pick) {
        cnt[p[0]][p[1]]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 10; j++) {
            if (cnt[i][j] > i) {
                ans++;
                break;
            }
        }
    }
    return ans;
}



};

// 方法：模拟
// 步骤：
// 1. 初始化一个二维数组 cnt，cnt[i][j] 表示玩家 i 获得了 j 个颜色的球的数量。
// 2. 遍历 pick 数组，统计每个玩家获得的球的数量。
// 3. 遍历 cnt 数组，对于每个玩家 i，如果 cnt[i][j] > i，则玩家 i 是胜利玩家。
// 4. 返回胜利玩家的数量。

// 时间复杂度：O(n * m)，其中 n 是玩家数目，m 是 pick 数组的长度。
// 空间复杂度：O(n * m)。