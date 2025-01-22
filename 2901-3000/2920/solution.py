# 树上二维dp，通过记忆化搜索实现，使用无向图的dfs算法遍历
# dp[v][decay]代表子树v已经折半decay次后能收集到的最多金币
class Solution:
    def maximumPoints(self, edges: List[List[int]], coins: List[int], k: int) -> int:
        n = len(edges) + 1
        adj = [[] for _ in range(n)]
        for e in edges:
            adj[e[0]].append(e[1])
            adj[e[1]].append(e[0])
        dp = [[-1 for _ in range(14)] for _ in range(n)]

        def dfs(root, decay, parent):
            # coins[i] <= 10000 < 2^14
            if decay >= 14:
                return 0

            # check
            if dp[root][decay] >= 0:
                return dp[root][decay]

            # res2, res1: decay or not decay
            res1 = (coins[root] >> decay) - k
            res2 = coins[root] >> (decay + 1)
            for v in adj[root]:
                # 无向图
                if v == parent:
                    continue
                res1 += dfs(v, decay, root)
                res2 += dfs(v, decay+1, root)

            # save
            dp[root][decay] = max(res1, res2)
            return dp[root][decay]

        return dfs(0, 0, -1)
