class Solution:
    def maxDifference(self, s: str) -> int:
        cnt = Counter(s)
        return max(v for v in cnt.values() if v % 2) - min(v for v in cnt.values() if not v % 2)
