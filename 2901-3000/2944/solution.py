# dp, 能ac但复杂度太高了
# 而且设置todo没有必要，i直接遍历[start, 2*start+1]即可
# 可使用单调队列优化至O(n) 
class Solution:
    def minimumCoins(self, prices: List[int]) -> int:
        n = len(prices)
        dp = [[0 for _ in range(n)] for _ in range(n)]
        
        def find(start, todo):
            if todo >= n:
                return 0

            if dp[start][todo]:
                return dp[start][todo]
            
            res = inf
            for i in range(start, todo + 1):
                res = min(res, prices[i] + find(i + 1, 2 * (i + 1)))
            
            dp[start][todo] = res
            return res
        
        return find(0, 0)
