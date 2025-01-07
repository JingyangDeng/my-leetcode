# O(n)
class Solution:
    def largestGoodInteger(self, num: str) -> str:
        return 3 * max(num[i] if num[i] == num[i-1] == num[i-2] else "" for i in range(2, len(num)))
