# recursively fill value
# e.g. [PAD, PAD, PAD]
# => [1, PAD, PAD], [PAD, 1, PAD], [PAD, PAD, 1]
# => [1, 2, 2], [2, 1, 2], [2, 2, 1]
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        PAD = -100
        template = [PAD] * len(nums)
        cnt = Counter(nums)
        res = [template]

        def recursive(lst, begin, to_fill, value, temp):
            if not to_fill:
                temp.append(lst.copy())
                return
            
            while begin < len(lst) and not lst[begin] == PAD:
                begin += 1
                
            if len(lst) - 1 - begin >= to_fill:
                # not fill @begin
                recursive(lst, begin+1, to_fill, value, temp)

            if begin >= len(lst):
                return
                
            # fill @begin
            lst[begin] = value
            recursive(lst, begin+1, to_fill-1, value, temp)
            # recover
            lst[begin] = PAD
                

        def fill(key):
            n = cnt[key]
            temp = []
            for r in res:
                recursive(r, 0, n, key, temp)
            return temp

        for k in cnt.keys():
            temp = fill(k)
            res = temp
        return res
