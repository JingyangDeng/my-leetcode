# O(m+n), hash
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        cnt = Counter(nums2)
        res = []
        for n in nums1:
            if n in cnt and cnt[n]:
                res.append(n)
                cnt[n] -= 1
        return res
