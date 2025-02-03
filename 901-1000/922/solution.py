# O(n)
class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        res = [0] * len(nums)
        p, q = 0, 1
        for n in nums:
            if n & 1:
                res[q] = n
                q += 2
            else:
                res[p] = n
                p += 2
        return res
