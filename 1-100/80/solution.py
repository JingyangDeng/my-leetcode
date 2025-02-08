# 快慢指针，O(n)
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        p, q = 0, 0
        while p < len(nums):
            value = nums[p]
            cnt = 0
            while p < len(nums) and nums[p] == value:
                cnt += 1
                if cnt <= 2:
                    nums[q] = value
                    q += 1
                p += 1
        return q
