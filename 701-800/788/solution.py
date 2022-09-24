# 暴力求解
class Solution:
    def rotatedDigits(self, n: int) -> int:
        cnt = 0
        d = {'0' : '0', '1' : '1', '2' : '5', '5' : '2', '6' : '9', '8' : '8', '9' : '6'}
        for i in range(1, n + 1):
            try:
                j = int(''.join([d[c] for c in str(i)]))
            except KeyError:
                continue
            if i != j:
                cnt += 1
        return cnt

