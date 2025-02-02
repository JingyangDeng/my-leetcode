# 双指针, O(n)
class Solution:
    def validPalindrome(self, s: str) -> bool:
        def check(left, right):
            while left < right and s[left] == s[right]:
                left, right = left + 1, right - 1
            return left, right, left >= right
        left, right, ok = check(0, len(s) - 1)
        if ok: return True
        _, _, ok1 = check(left + 1, right)
        if ok1: return True
        _, _, ok2 = check(left, right - 1)
        return ok2
