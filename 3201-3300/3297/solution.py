#双指针维护最小valid区间, O(m+n)
from collections import Counter

class Solution:
    def validSubstringCount(self, word1: str, word2: str) -> int:
        c1 = Counter()
        c2 = Counter(word2)
        l, r = 0, 0

        while r < len(word1):
            c1[word1[r]] += 1
            f = 1
            for k in c2.keys():
                if c1[k] < c2[k]:
                    r += 1
                    f = 0
                    break
            if f:
                break

        res = len(word1) - r
        while r < len(word1):
            k = word1[l]
            c1[k] -= 1
            l += 1
            while r < len(word1) and c1[k] < c2[k]:
                r += 1
                if r < len(word1):
                    c1[word1[r]] += 1
            
            res += len(word1) - r

        return res
