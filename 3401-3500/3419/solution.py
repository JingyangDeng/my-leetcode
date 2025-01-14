# 二分答案+dfs验证
class Solution:
    def minMaxWeight(self, n: int, edges: List[List[int]], threshold: int) -> int:
        adj = [[] for _ in range(n)]
        max_w = 0
        for e in edges:
            adj[e[1]].append((e[0], e[2]))
            max_w = max(max_w, e[2])
        
        def check(limit):
            visited = [0 for _ in range(n)]
            def dfs(node, visited):
                visited[node] = 1
                for dest, w in adj[node]:
                    if w <= limit and not visited[dest]:
                        dfs(dest, visited)
            dfs(0, visited)
            return sum(visited) == n
        
        l, r = 0, max_w + 1
        while l < r:
            mid = (l + r) >> 1
            if check(mid):
                r = mid
            else:
                l = mid + 1
        return l if l <= max_w else -1
