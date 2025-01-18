# hard, 2545
# DP all possible OR + enumerate XOR
class Solution:
    def maxValue(self, nums: List[int], k: int) -> int:
        n = len(nums)
        def dp(nums):
            # find all possible OR values: 
            # select j numbers from the begining i numbers
            res = []
            mem = [set() for _ in range(k+1)]
            mem[0].add(0)
            for i in range(0, n+1):
                for j in range(min(i, k), 0, -1):
                    mem[j].update(set(nums[i-1] | x for x in mem[j-1]))
                res.append(mem[k].copy())
            return res
            
        prefix = dp(nums)
        suffix = dp(nums[::-1])
        # enumerate to find the maximum XOR
        return max(max(a ^ b for a in prefix[i] for b in suffix[n-i]) for i in range(k, n-k+1))

