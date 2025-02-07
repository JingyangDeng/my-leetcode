# O(mn) 动态规划，考虑从(0,0)到(i,j)的方案数
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m, n = len(obstacleGrid), len(obstacleGrid[0])
        dp = [[0 if obstacleGrid[i][j] == 1 else -1 for j in range(n)] for i in range(m)]
        
        fill_zero = 0
        for i in range(m):
            if fill_zero:
                dp[i][0] = 0
            elif dp[i][0] == 0:
                fill_zero = 1
            else:
                dp[i][0] = 1
        
        fill_zero = 0
        for j in range(n):
            if fill_zero:
                dp[0][j] = 0
            elif dp[0][j] == 0:
                fill_zero = 1
            else:
                dp[0][j] = 1
        
        for i in range(1, m):
            for j in range(1, n):
                if dp[i][j] < 0:
                    dp[i][j] = dp[i-1][j] + dp[i][j-1]
        
        return dp[m-1][n-1]
