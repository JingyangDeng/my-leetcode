# DP
class Solution:
    def maximumAmount(self, coins: List[List[int]]) -> int:
        m, n = len(coins), len(coins[0])
        dp = [[[-250000001 for _ in range(3)] for _ in range(n)] for _ in range(m)]
        dp[m-1][n-1][2] = coins[m-1][n-1]
        dp[m-1][n-1][1] = coins[m-1][n-1] if coins[m-1][n-1] > 0 else 0
        dp[m-1][n-1][0] = coins[m-1][n-1] if coins[m-1][n-1] > 0 else 0
        for i in range(m-1, -1, -1):
            for j in range(n-1, -1, -1):
                for k in range(2, -1, -1):
                    if i < m-1:
                        dp[i][j][k] = max(dp[i+1][j][k] + coins[i][j], dp[i][j][k])
                        if coins[i][j] < 0 and k < 2:
                            dp[i][j][k] = max(dp[i+1][j][k+1], dp[i][j][k])
                    if j < n-1:
                        dp[i][j][k] = max(dp[i][j+1][k] + coins[i][j], dp[i][j][k])
                        if coins[i][j] < 0 and k < 2:
                            dp[i][j][k] = max(dp[i][j+1][k+1], dp[i][j][k])
        #print(dp[m-1][n-1][1])
        return dp[0][0][0]
