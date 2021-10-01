//简单的Hash表
func destCity(paths [][]string) string {
    dic := make(map[string]bool, 100)
    for _, v := range paths {
        dic[v[0]] = true
    }
    for _, v := range paths {
        if _, ok := dic[v[1]]; !ok {
            return v[1]
        }
    }
    return ""
}

