#一次遍历
class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        line1 = 'qwertyuiopQWERTYUIOP'
        line2 = 'asdfghjklASDFGHJKL'
        line3 = 'zxcvbnmZXCVBNM'
        ret = []
        for w in words:
            line = line1 if w[0] in line1 else line2 if w[0] in line2 else line3
            f = 1
            for c in w:
                if c not in line:
                    f = 0
                    break
            if f:
                ret.append(w)
        return ret
