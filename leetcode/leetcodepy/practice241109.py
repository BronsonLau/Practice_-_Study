# 3242. 设计相邻元素求和服务

# 给你一个 n x n 的二维数组 grid，它包含范围 [0, n2 - 1] 内的不重复元素。

# 实现 neighborSum 类：

# neighborSum(int [][]grid) 初始化对象。
# int adjacentSum(int value) 返回在 grid 中与 value 相邻的元素之和，相邻指的是与 value 在上、左、右或下的元素。
# int diagonalSum(int value) 返回在 grid 中与 value 对角线相邻的元素之和，对角线相邻指的是与 value 在左上、右上、左下或右下的元素。

class NeighborSum:
    dirs = [
        [(-1, 0), (1, 0), (0, -1), (0, 1)],
        [(-1, -1), (-1, 1), (1, -1), (1, 1)],
    ]

    def __init__(self, grid: List[List[int]]):
        self.pos = dict()
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                self.pos[grid[i][j]] = (i, j)
        self.grid = grid

    def adjacentSum(self, value: int) -> int:
        return self.getSum(value, 0)

    def diagonalSum(self, value: int) -> int:
        return self.getSum(value, 1)
    
    def getSum(self, value: int, idx: int) -> int:
        x, y = self.pos[value]
        ans = 0
        for (dx, dy) in NeighborSum.dirs[idx]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < len(self.grid) and 0 <= ny < len(self.grid[0]):
                ans += self.grid[nx][ny]
        return ans

## 输入具有复杂性，要注意输入的类型，写合适的操作。