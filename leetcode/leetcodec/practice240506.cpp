// 动态规划 不会
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int cherryPickup(int** grid, int gridSize, int* gridColSize){
    int n = gridSize;
    int ***f = (int ***)malloc(sizeof(int **) * (n * 2 - 1));
    for (int i = 0; i < n * 2 - 1; ++i) {
        f[i] = (int **)malloc(sizeof(int *) * n);
        for (int j = 0; j < n; ++j) {
            f[i][j] = (int *)malloc(sizeof(int) * n);
            for (int k = 0; k < n; ++k) {
                f[i][j][k] = INT_MIN;
            }
        }
    }
    f[0][0][0] = grid[0][0];
    for (int k = 1; k < n * 2 - 1; ++k) {
        for (int x1 = MAX(k - n + 1, 0); x1 <= MIN(k, n - 1); ++x1) {
            int y1 = k - x1;
            if (grid[x1][y1] == -1) {
                continue;
            }
            for (int x2 = x1; x2 <= MIN(k, n - 1); ++x2) {
                int y2 = k - x2;
                if (grid[x2][y2] == -1) {
                    continue;
                }
                int res = f[k - 1][x1][x2]; // 都往右
                if (x1) {
                    res = MAX(res, f[k - 1][x1 - 1][x2]); // 往下，往右
                }
                if (x2) {
                    res = MAX(res, f[k - 1][x1][x2 - 1]); // 往右，往下
                }
                if (x1 && x2) {
                    res = MAX(res, f[k - 1][x1 - 1][x2 - 1]); // 都往下
                }
                res += grid[x1][y1];
                if (x2 != x1) { // 避免重复摘同一个樱桃
                    res += grid[x2][y2];
                }
                f[k][x1][x2] = res;
            }
        }
    }
    int ret = MAX(f[n * 2 - 2][n - 1][n - 1], 0);
    for (int i = 0; i < n * 2 - 1; ++i) {
        for (int j = 0; j < n; ++j) {
            free(f[i][j]);
        }
        free(f[i]);
    }
    free(f);
    return ret;
}

