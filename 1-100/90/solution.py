# 枚举
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        cnt = Counter(nums)
        res = [[]]
        
        def update(k):
            tmp = []
            for s in res:
                ns = s.copy()
                for _ in range(cnt[k]):
                    ns.append(k)
                    tmp.append(ns.copy())
            res.extend(tmp)
        
        for k in cnt.keys():
            update(k)

        return res
