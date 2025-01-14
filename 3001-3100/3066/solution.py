# priority queue, O(nlogn)
class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        heapify(nums)
        res = 0
        while nums:
            a = heappop(nums)
            if a >= k:
                break
            b = heappop(nums)
            heappush(nums, 2 * a + b)
            res += 1
        return res
