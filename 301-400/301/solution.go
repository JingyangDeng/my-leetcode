//dfs + 剪枝
func removeInvalidParentheses(s string) []string {
    left, right := getRemoveNum(s)
    m := make(map[string]bool, 0)
    cur := ""
    
    var dfs func(p, l, r, cnt int)
    dfs = func(p, l, r, cnt int) {
        if l > left || r > right || cnt < 0 {
            return
        }
        if p == len(s) {
            if cnt == 0 {
                m[cur] = true
            }
            return
        }
        if s[p] == '(' {
            dfs(p+1, l+1, r, cnt)
            cur += "("
            dfs(p+1, l, r, cnt+1)
            cur = cur[:len(cur)-1]
        } else if s[p] == ')' {
            dfs(p+1, l, r+1, cnt)
            cur += ")"
            dfs(p+1, l, r, cnt-1)
            cur = cur[:len(cur)-1]
        } else {
            cur += string(s[p])
            dfs(p+1, l, r, cnt)
            cur = cur[:len(cur)-1]
        }
    }
    dfs(0, 0, 0, 0)

    ret := make([]string, 0)
    for str, _ := range m {
        ret = append(ret, str)
    }
    return ret
}

func getRemoveNum(s string) (int, int) {
    l, r := 0, 0
    for _, c := range s {
        if c == '(' {
            l++
        } else if c == ')' {
            if l > 0 {
                l--
            } else {
                r++
            }
        }
    }
    return l, r
}
