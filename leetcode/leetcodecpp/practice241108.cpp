// 3235. 判断矩形的两个角落是否可达
// 已解答
// 困难
// 相关标签
// 相关企业
// 提示
// 给你两个正整数 xCorner 和 yCorner 和一个二维整数数组 circles ，其中 circles[i] = [xi, yi, ri] 表示一个圆心在 (xi, yi) 半径为 ri 的圆。

// 坐标平面内有一个左下角在原点，右上角在 (xCorner, yCorner) 的矩形。你需要判断是否存在一条从左下角到右上角的路径满足：路径 完全 在矩形内部，不会 触碰或者经过 任何 圆的内部和边界，同时 只 在起点和终点接触到矩形。

// 如果存在这样的路径，请你返回 true ，否则返回 false 。

class Solution:
    def canReachCorner(self, X: int, Y: int, circles: List[List[int]]) -> bool:

        def find(index: int) -> int:
            if parent[index] != index:
                parent[index] = find(parent[index])
            return parent[index]
        
        def union(index1: int, index2: int):
            parent[find(index1)] = find(index2)
        
        n = len(circles)
        parent = list(range(n+2))

        def PinO(xx,yy,x,y,r):
            return (xx-x)*(xx-x)+(yy-y)*(yy-y)<=r*r

        def crossV(x,y,r,xx,y1,y2):
            if y1>=y: return PinO(xx,y1,x,y,r)
            if y2<=y: return PinO(xx,y2,x,y,r)
            return abs(xx-x)<=r

        def crossH(x,y,r,x1,x2,yy):
            if x1>=x: return PinO(x1,yy,x,y,r)
            if x2<=x: return PinO(x2,yy,x,y,r)
            return abs(yy-y)<=r

        for i in range(n):
            cx1,cy1,r1 = circles[i]
            if crossV(cx1,cy1,r1,0,0,Y) or crossH(cx1,cy1,r1,0,X,Y):
                union(i,n)
            if crossV(cx1,cy1,r1,X,0,Y) or crossH(cx1,cy1,r1,0,X,0):
                union(i,n+1)
            for j in range(i+1,n):
                cx2,cy2,r2 = circles[j]
                d = (cx1-cx2)*(cx1-cx2)+(cy1-cy2)*(cy1-cy2)-(r1+r2)*(r1+r2)
                x3 = cx1+(cx2-cx1)*(r1/(r1+r2))
                y3 = cy1+(cy2-cy1)*(r1/(r1+r2))
                if d<=0 and 0<=x3<=X and 0<=y3<=Y:
                    union(i,j)
        return find(n)!=find(n+1)

// 并查集方法：从坐下到右上，相比于逆向DFS更加直接，但耗时更长。