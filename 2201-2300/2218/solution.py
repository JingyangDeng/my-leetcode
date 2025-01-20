# dp (knapsack)
# consider p[i][0,...,m-1] as a single item that costs m ops
# dp[i][j]: max value when selecting from 0, ..., i-1 piles within j ops
class Solution:
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        piles = [list(accumulate(p)) for p in piles]
        n = len(piles)
        dp = [[0 for _ in range(k+1)] for _ in range(n)]
        for i in range(n):
            for j in range(k+1):
                if not j:
                    continue
                if not i:
                    dp[i][j] = piles[i][j-1] if j-1 < len(piles[i]) else 0
                    continue
                dp[i][j] = max(dp[i-1][j], dp[i][j])
                for m in range(1, min(j, len(piles[i]))+1):
                    dp[i][j] = max(dp[i][j], dp[i-1][j-m] + piles[i][m-1])
        return dp[-1][-1]
