# for loop, O(n)
class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        res = -inf
        for n in nums:
            if abs(n) < abs(res) or (abs(n) == abs(res) and n > res):
                res = n
        return res
