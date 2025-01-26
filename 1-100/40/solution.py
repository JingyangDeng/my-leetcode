# dp, convert to knapsack
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        cnt = Counter(candidates)
        lst = sorted([(k, v) for k, v in cnt.items()])
        res = []
        def dp(target, p, cur_res):
            if p < 0:
                return
            for i in range(lst[p][1] + 1):
                cur = cur_res.copy()
                if i * lst[p][0] <= target:
                    cur.extend([lst[p][0]] * i)
                    new_target = target - i * lst[p][0]
                    if new_target == 0:
                        res.append(cur)
                    else:
                        dp(new_target, p-1, cur)
        dp(target, len(lst)-1, [])
        return res
