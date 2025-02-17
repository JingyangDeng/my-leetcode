# O(n)
class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        res, cur = -1, 0
        cnt = Counter()
        for a in arr:
            cnt[a] += 1
            if cnt[a] > cur:
                cur = cnt[a]
                res = a
        return res
