#尽量每种都至少给1颗，直到已经分到n/2颗
class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        return min(len(set(candyType)), len(candyType) >> 1)
