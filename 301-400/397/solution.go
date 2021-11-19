//记忆化DFS
func integerReplacement(n int) int {
    m := make(map[int]int)
    var dfs func(n int) int
    dfs = func(n int) (ret int) {
        if ret, ok := m[n]; ok {
            return ret
        }
        if n == 1 {
            return 0
        }
        if (n & 1) == 1 {
            ret = 1 + minInt(dfs(n - 1), dfs(n + 1))
        } else {
            ret = 1 + dfs(n >> 1)
        }
        m[n] = ret
        return ret
    }
    return dfs(n)
}

func minInt (a, b int) int {
    if a < b {
        return a
    }
    return b
}
