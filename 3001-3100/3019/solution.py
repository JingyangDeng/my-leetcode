# O(n)
class Solution:
    def countKeyChanges(self, s: str) -> int:
        s = s.lower()
        return sum(s[i] != s[i+1] for i in range(len(s)-1))
