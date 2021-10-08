#快速选择
class Solution:
    def _compare(self, s1, s2):
        if len(s1) != len(s2):
            return len(s1) > len(s2)
        return s1 > s2

    def _quick_select(self, nums, left, right):
        p = random.randint(left, right-1)
        nums[p], nums[right-1] = nums[right-1], nums[p]
        pointer = left
        for i in range(left, right-1):
            if self._compare(nums[i], nums[right-1]):
                nums[pointer], nums[i] = nums[i], nums[pointer]
                pointer += 1
        nums[pointer], nums[right-1] = nums[right-1], nums[pointer]
        pointer_max = pointer
        while pointer_max < right and nums[pointer] == nums[pointer_max]:
            pointer_max += 1
        return pointer, pointer_max

    def kthLargestNumber(self, nums: List[str], k: int) -> str:
        left, right = 0, len(nums)
        while True:
            p, q = self._quick_select(nums, left, right)
            if p <= k-1 and k <= q:
                break
            elif q < k:
                left = q
            else:
                right = p
        return nums[k-1]

