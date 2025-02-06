# 模拟，往前走不了就右拐
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res = [[0 for _ in range(n)] for _ in range(n)]
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        i, j, p = 0, 0, 0
        for k in range(1, n * n + 1):
            res[i][j] = k
            di, dj = directions[p]
            # do not need to check i + di < 0 or j + dj < 0
            if i + di >= n or j + dj >= n or res[i+di][j+dj] > 0:
                p = (p + 1) % 4
                di, dj = directions[p]
            i, j = i + di, j + dj
        return res
