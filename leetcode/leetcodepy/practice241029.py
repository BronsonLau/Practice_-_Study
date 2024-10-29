class Solution:
    def validStrings(self, n: int) -> List[str]:
        res = []
        def dfs(arr: List[str]) -> None:
            if len(arr) == n:
                res.append(''.join(arr))
            else:
                if arr == [] or arr[-1] == '1':
                    arr.append('0')
                    dfs(arr)
                    arr.pop()
                arr.append('1')
                dfs(arr)
                arr.pop()
        dfs([])
        return res