# Kanade算法，考虑以第i位为结尾的最大子序列和
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        ret = cur_max = -1 << 30
        for n in nums:
            cur_max = n + cur_max if cur_max > 0 else n
            ret = max(ret, cur_max)
        return ret
