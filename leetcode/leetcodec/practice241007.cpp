// 871.最低加油次数
// 汽车从起点出发驶向目的地，该目的地位于出发位置东面 target 英里处。

// 沿途有加油站，用数组 stations 表示。其中 stations[i] = [positioni, fueli] 表示第 i 个加油站位于出发位置东面 positioni 英里处，并且有 fueli 升汽油。

// 假设汽车油箱的容量是无限的，其中最初有 startFuel 升燃料。它每行驶 1 英里就会用掉 1 升汽油。当汽车到达加油站时，它可能停下来加油，将所有汽油从加油站转移到汽车中。

// 为了到达目的地，汽车所必要的最低加油次数是多少？如果无法到达目的地，则返回 -1 。

// 注意：如果汽车到达加油站时剩余燃料为 0，它仍然可以在那里加油。如果汽车到达目的地时剩余燃料为 0，仍然认为它已经到达目的地。

 

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int minRefuelStops(int target, int startFuel, int** stations, int stationsSize, int* stationsColSize){
    long *dp = (long *)malloc(sizeof(long) * (stationsSize + 1));
    memset(dp, 0, sizeof(long) * (stationsSize + 1));
    dp[0] = startFuel;
    for (int i = 0; i < stationsSize; i++) {
        for (int j = i; j >= 0; j--) {
            if (dp[j] >= stations[i][0]) {
                dp[j + 1] = MAX(dp[j + 1], dp[j] + stations[i][1]);
            }
        }
    }
    for (int i = 0; i <= stationsSize; i++) {
        if (dp[i] >= target) {
            free(dp);
            return i;
        }
    }
    free(dp);
    return -1;
}