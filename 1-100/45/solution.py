# dp, O(n*max(nums))
# 贪心：考虑从0出发k(=1, 2, ...)步可达的最远距离，O(n)
class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        
        @cache
        def dp(i):
            if i == n-1:
                return 0
            max_steps = min(n-i-1, nums[i])
            if max_steps == 0:
                return inf
            return 1 + min(dp(i+j) for j in range(1, max_steps+1))
        
        return dp(0)
        
