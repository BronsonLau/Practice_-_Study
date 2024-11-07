# 3235. 判断矩形的两个角落是否可达
# 已解答
# 困难
# 相关标签
# 相关企业
# 提示
# 给你两个正整数 xCorner 和 yCorner 和一个二维整数数组 circles ，其中 circles[i] = [xi, yi, ri] 表示一个圆心在 (xi, yi) 半径为 ri 的圆。

# 坐标平面内有一个左下角在原点，右上角在 (xCorner, yCorner) 的矩形。你需要判断是否存在一条从左下角到右上角的路径满足：路径 完全 在矩形内部，不会 触碰或者经过 任何 圆的内部和边界，同时 只 在起点和终点接触到矩形。

# 如果存在这样的路径，请你返回 true ，否则返回 false 。

class Solution:
    def canReachCorner(self, xCorner: int, yCorner: int, circles: List[List[int]]) -> bool:

        def pointInCircle(px: int, py: int, x: int, y: int, r: int) -> bool:
            return (x - px) ** 2 + (y - py) ** 2 <= r ** 2

        def circleIntersectsTopLeftOfRectangle(x: int, y: int, r: int, xCorner: int, yCorner: int) -> bool:
            return (abs(x) <= r and 0 <= y <= yCorner) or (0 <= x <= xCorner and abs(y - yCorner) <= r) or pointInCircle(x, y, 0, yCorner, r)
        
        def circleIntersectsBottomRightOfRectangle(x: int, y: int, r: int, xCorner: int, yCorner: int) -> bool:
            return (abs(y) <= r and 0 <= x <= xCorner) or (0 <= y <= yCorner and abs(x - xCorner) <= r) or (pointInCircle(x, y, xCorner, 0, r))

        def circlesIntersectInRectangle(x1: int, y1: int, r1: int, x2: int, y2: int, r2: int, xCorner: int, yCorner: int) -> bool:
            return (x1 - x2) ** 2 + (y1 - y2) ** 2 <= (r1 + r2) ** 2 and x1 * r2 + x2 * r1 < (r1 + r2) * xCorner and y1 * r2 + y2 * r1 < (r1 + r2) * yCorner

        visited = [False] * len(circles)
        def dfs(i: int) -> bool:
            x1, y1, r1 = circles[i]
            if circleIntersectsBottomRightOfRectangle(x1, y1, r1, xCorner, yCorner):
                return True
            visited[i] = True
            for j, (x2, y2, r2) in enumerate(circles):
                if (not visited[j]) and circlesIntersectInRectangle(x1, y1, r1, x2, y2, r2, xCorner, yCorner) and dfs(j):
                    return True
            return False

        for i, (x, y, r) in enumerate(circles):
            if pointInCircle(0, 0, x, y, r) or pointInCircle(xCorner, yCorner, x, y, r):
                return False
            if (not visited[i]) and circleIntersectsTopLeftOfRectangle(x, y, r, xCorner, yCorner) and dfs(i):
                return False
        return True

# 采用DFS方法，遍历障碍物圆，而不是遍历矩形，这样可以减少遍历次数，提高效率。
# 思路

# 首先我们考虑 circles 只有一个圆。在三种情况下，不存在这样的路径：

# 起点在圆内或圆上（圆内或圆上不影响结果，下文均简写为圆内）；
# 终点在圆内；
# 圆与矩形的左侧边或者上侧边相切或相交（相切或相交不影响结果，下文均简写为相交），并且圆与矩形的右侧边或者下侧边相交。
# 前两种情况好理解，题目规定路径不能触碰圆的边界或者内部，因此当起点或者终点位于圆内时，肯定不存在这样的路径。第三种情况，圆作为一个单一的障碍物，既与矩形的左上边界相交，又与矩形的右下边界相交，使得不存在一条路径可以从矩形内部经过，又不碰触圆的边界或者内部。

# 接下来，考虑 circles 中有多个圆的情况。类似的，上文讨论的前两种情况仍然成立，当起点或终点位于某一个圆内时，不存在这样的路径。当有多个圆时，圆可能会在矩形内相交。当圆在矩形内相交时，这些圆可以合并成为一个障碍物，当这个合并的障碍物也满足与矩形的左上边界相交，且与矩形的右下边界相交，那么就不存在所求的路径。当圆的相交区域在矩形之外时，这些圆不能进行合并，因为相交的区域不会阻止在矩形内部的路径的生成。这样，我们可以从与矩形的左上边界相交的圆形开始深度优先搜索，然后遍历可以与当前圆合并的相邻点，重复如此，直到遍历到与矩形的右下边界相交的圆，这样的情况下，就表示不存在所求的路径。如果遍历完所有的圆后，都无法遍历到与矩形的右下边界相交的圆，那么表示存在所求的路径。

# 特殊情况是圆的相交区域的一部分位于矩形内，另一部分位于矩形外，即圆的相交区域又和矩形的边相交。按照上述的推导，这些圆需要进行合并。在实际中，我们可以对它们进行合并，也可以不对它们进行合并。理由如下：当两个圆的相交区和矩形的边相交时，这两个圆本身就都与矩形的边相交。如果这两个圆本身就都与矩形的左上边界相交，那么我们可以不合并它们，因为它们可以各自作为起点。如果这两个圆本身就都与矩形的右下边界相交，那么我们可以不合并它们，因为它们可以各自作为终点。不存在其中一个圆仅与矩形的左上边界相交，另一个圆仅与矩形的右下边界相交的情况。这就得出了接下来的结论：判断两个相交的圆是否需要合并时，我们可以任取相交区域的一点，如果点在矩形内部，那么我们合并它们，否则不合并。

# 接下来，我们需要将上文提到的几何关系用代码来表示。

# 首先是判断点是否在圆内，这个我们可以用点到圆心的距离和半径进行比较。为了避免精度问题，我们可以将两边都进行平方操作。

# 接下来是判断圆是否与矩形的左上边界相交。记圆心的坐标为 (x,y)，半径为 r。圆心需要位于图中的两个实线矩形或者圆内。在已经满足圆不包含起点或者终点的情况下，前一句话的条件已经足够。

# 判断圆是否与右下边界相交，与上面的判断类似。

# 最后是判断两个相交的圆内的任意一点是否与位于矩形内部。记两个圆的圆心分别为 O 
# 1
# ​
#  ，O 
# 2
# ​
#  ，坐标分别为 (x 
# 1
# ​
#  ,y 
# 1
# ​
#  )，(x 
# 2
# ​
#  ,y 
# 2
# ​
#  )，半径分别为 r 
# 1
# ​
#  ，r 
# 2
# ​
#  。首先判断两圆是否相交，也可以用圆心之间的距离与半径之和进行比较。如果相交，再在线段 O 
# 1
# ​
#  O 
# 2
# ​
#   取点 A 满足  
# ∣O 
# 1
# ​
#  O 
# 2
# ​
#  ∣
# ∣O 
# 1
# ​
#  A∣
# ​
#   =  
# r 
# 1
# ​
#  +r 
# 2
# ​
 
# r 
# 1
# ​
 
# ​
#  。这样点 A 一定满足在两圆的相交区域，因为点 A 到两个圆心的距离均小于等于对应的半径。计算得到点 A 的坐标为 ( 
# r 
# 1
# ​
#  +r 
# 2
# ​
 
# x 
# 1
# ​
#  ×r 
# 2
# ​
#  +x 
# 2
# ​
#  ×r 
# 1
# ​
 
# ​
#  , 
# r 
# 1
# ​
#  +r 
# 2
# ​
 
# y 
# 1
# ​
#  ×r 
# 2
# ​
#  +y 
# 2
# ​
#  ×r 
# 1
# ​
 
# ​
#  )。再判断这个点是否位于矩形内部即可。这样选取点 A，也可以避免精度带来的误差。

