# O(n), 遍历，记录每个数最近出现的下标
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        d = {}
        for i, n in enumerate(nums):
            if n in d and i - d[n] <= k:
                return True
            d[n] = i
        return False
