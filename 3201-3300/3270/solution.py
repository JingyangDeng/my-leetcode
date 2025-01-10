# one-line code
class Solution:
    def generateKey(self, num1: int, num2: int, num3: int) -> int:
        return int("".join((min(f"{n:04d}"[i] for n in (num1, num2, num3)) for i in range(4))))
