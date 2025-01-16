# sliding window, O(n)
class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        if k == 0: return 1
        
        d = Counter()
        l, r, cur, res = 0, 0, 0, len(nums)
        
        def update(ans, n, add):
            i = 0
            while n:
                b = n & 1
                d[i] += b * add
                if b:
                    if add == 1 and d[i] == 1:
                        ans += (1 << i)
                    elif add == -1 and d[i] == 0:
                        ans -= (1 << i)
                n, i = n >> 1, i + 1
            return ans

        while r < len(nums):
            while cur < k and r < len(nums):
                cur = update(cur, nums[r], 1)
                r += 1
            if l == 0 and r == len(nums) and cur < k: return -1
            res = min(res, r-l)
            while l < len(nums) and cur >= k:
                cur = update(cur, nums[l], -1)
                l += 1
            res = min(res, r-l+1)
        return res
