# 暴力求解
class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        s = set()
        for i in range(len(words)):
            for j in range(i+1, len(words)):
                if words[i] in words[j]:
                    s.add(words[i])
                elif words[j] in words[i]:
                    s.add(words[j])
        return list(s)

