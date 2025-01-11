# one-line code
class Solution:
    def largestCombination(self, candidates: List[int]) -> int:
        return max(sum((1 << i) & c > 0 for c in candidates) for i in range(24))
