class Solution:
    def minimumValueSum(self, nums: List[int], andValues: List[int]) -> int:
        inf = (1 << 20) - 1

        @cache
        def dfs(i, j, cur):
            if i == len(nums) and j == len(andValues):
                return 0
            if i == len(nums) or j == len(andValues):
                return inf
            cur &= nums[i]
            if cur & andValues[j] < andValues[j]:
                return inf
            res = dfs(i + 1, j, cur)
            if cur == andValues[j]:
                res = min(res, dfs(i + 1, j + 1, inf) + nums[i])
            return res

        res = dfs(0, 0, inf)
        return res if res < inf else -1

# 作者：力扣官方题解
# 链接：https://leetcode.cn/problems/minimum-sum-of-values-by-dividing-array/solutions/2877228/hua-fen-shu-zu-de-dao-zui-xiao-de-zhi-zh-dcik/
# 来源：力扣（LeetCode）
# 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。