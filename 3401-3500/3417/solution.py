# simulation
class Solution:
    def zigzagTraversal(self, grid: List[List[int]]) -> List[int]:
        m, n = len(grid), len(grid[0])
        skip = 0
        res = []
        for i in range(m):
            if i % 2:
                for j in range(n-1, -1, -1):
                    if skip:
                        skip = 0
                    else:
                        res.append(grid[i][j])
                        skip = 1
            else:
                for j in range(n):
                    if skip:
                        skip = 0
                    else:
                        res.append(grid[i][j])
                        skip = 1
        return res
