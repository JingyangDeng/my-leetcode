#直接实现
class Solution:
    def minNumber(self, nums1: List[int], nums2: List[int]) -> int:
        s = set(nums1) & set(nums2)
        if len(s):
            return min(s)
        n1, n2 = min(nums1), min(nums2)
        return n1 + n2 + 9 * min(n1, n2)
        
