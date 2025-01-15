# double loop, O(n^2)
# 任意子数组的长度增加元素后按位或运算的结果一定大于等于增加前的结果，满足单调性。
# 由此可知当每次固定数组的右端点时，我们可以使用滑动窗口来找到最短特别子数组的长度。

class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        res, f = len(nums), 0
        for i in range(len(nums)):
            temp = 0
            for j in range(i, min(len(nums), i+res)):
                temp |= nums[j]
                if temp >= k:
                    res, f = j - i + 1, 1
                    break
        return res if f else -1
