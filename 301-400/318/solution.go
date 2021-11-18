//状态压缩 位运算
func maxProduct(words []string) int {
    m := make(map[int]int, 1000)
    for i, w := range words {
        hash := 0
        for _, c := range w {
            hash |= (1 << int(c - 'a'))
        }
        m[i] = hash
    }
    ret := 0
    for i := 0; i < len(words); i++ {
        for j := i + 1; j < len(words); j++ {
            if (m[i] & m[j]) == 0 && len(words[i]) * len(words[j]) > ret {
                ret = len(words[i]) * len(words[j])
            }
        }
    }
    return ret
}

