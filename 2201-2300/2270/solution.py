#prefix sum, O(n)
class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        su = sum(nums)
        cur, res = 0, 0
        for i in range(len(nums)-1):
            cur += nums[i]
            res += (cur >= su - cur)
        return res
