# O(logn)
class Solution:
    def evenOddBit(self, n: int) -> List[int]:
        binary = []
        while n:
            binary.append(n & 1)
            n >>= 1
        return [sum(b for i, b in enumerate(binary) if not i & 1), 
                sum(b for i, b in enumerate(binary) if i & 1)]
