# 661. 图片平滑器
# 图像平滑器 是大小为 3 x 3 的过滤器，用于对图像的每个单元格平滑处理，平滑处理后单元格的值为该单元格的平均灰度。

# 每个单元格的  平均灰度 定义为：该单元格自身及其周围的 8 个单元格的平均值，结果需向下取整。（即，需要计算蓝色平滑器中 9 个单元格的平均值）。

# 如果一个单元格周围存在单元格缺失的情况，则计算平均灰度时不考虑缺失的单元格（即，需要计算红色平滑器中 4 个单元格的平均值）。



# 给你一个表示图像灰度的 m x n 整数矩阵 img ，返回对图像的每个单元格平滑处理后的图像 。

class Solution:
    def imageSmoother(self, M: List[List[int]]) -> List[List[int]]:
        if not (len(M) or len(M[0])):
            return M

        smoothedImage = [] 
        directions = [[-1,-1],[-1,0],[-1,1],
                      [0,-1], [0,0], [0,1],
                      [1,-1], [1,0], [1,1]]

        for x in range(len(M)):
            oneRow = []
            for y in range(len(M[0])):
                sum = 0
                count = 0
                # 计算有效邻居点的加权平均
                for direct in directions:
                    if y+direct[0]>=0 and y+direct[0]<len(M[0]) and x+direct[1]>=0 and x+direct[1]<len(M):
                        sum += M[x+direct[1]][y+direct[0]]
                        count += 1
                oneRow.append(sum//count)
            smoothedImage.append(oneRow)
        return smoothedImage

## 事关平滑卷积的处理方法，需要考虑边界情况，以及对应的权重计算方法

