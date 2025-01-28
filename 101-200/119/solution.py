# A(n, i) = n!/i!(n-i)! => A(n, i+1) = A(n, i) * (n-i) / (i+1)
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        res = [1]
        for i in range(rowIndex):
            res.append(res[i] * (rowIndex-i) // (i+1))
        return res
