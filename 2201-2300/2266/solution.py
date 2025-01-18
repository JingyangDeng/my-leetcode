# dp, O(n)
# 考虑pressedKeys[i ... n-1]的方案数，讨论pressedKeys[i ~ i+3]是否相等
# "7" and "9" 要作特殊处理
class Solution:
    def countTexts(self, pressedKeys: str) -> int:
        n = len(pressedKeys)
        dp = [0] * n
        dp[-1] = 1
        mod = 1000000007
        for i in range(n-2, -1, -1):
            dp[i] += dp[i+1]
            if pressedKeys[i] == pressedKeys[i+1]:
                dp[i] += (dp[i+2] if i+2 < n else 1)
                if i+2 < n and pressedKeys[i] == pressedKeys[i+2]:
                    dp[i] += (dp[i+3] if i+3 < n else 1)
                    if i+3 < n and pressedKeys[i] == pressedKeys[i+3] and pressedKeys[i] in ["7", "9"]:
                        dp[i] += (dp[i+4] if i+4 < n else 1)
            dp[i] %= mod
        return dp[0]
