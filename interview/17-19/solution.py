# a + b = su
# a^2 + b^2 = sqsu
# ==> 2a^2 -2a*su + su^2 - sqsu = 0
class Solution:
    def missingTwo(self, nums: List[int]) -> List[int]:
        n = len(nums) + 2
        su = n * (n + 1) / 2 - sum(nums)
        sqsu = n * (n + 1) * (2 * n + 1) / 6 - sum([num * num for num in nums])
        a, b, c = 2, -2 * su, su * su - sqsu
        x = (-b + sqrt(b * b - 4 * a * c)) / (2 * a)
        y = su - x
        return [int(x), int(y)]
