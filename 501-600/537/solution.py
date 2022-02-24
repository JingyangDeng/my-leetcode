# 直接计算
class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        num1 = num1[:-1].split('+')
        num2 = num2[:-1].split('+')
        a, b = int(num1[0]), int(num1[1])
        c, d = int(num2[0]), int(num2[1])
        return str(a * c - b * d) + '+' + str(a * d + b * c) + 'i'
