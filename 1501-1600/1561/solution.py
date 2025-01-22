# greedy, O(nlogn)
class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        piles.sort()
        n = len(piles)
        return sum(piles[n // 3 : n : 2])
