//状态压缩 + hash
func reorderedPowerOf2(n int) bool {
    encode := func(m int) int {
        cnt := make([]int, 10)
        for m > 0 {
            cnt[m % 10]++
            m /= 10
        }
        ret := 0
        for i := 0; i < 10; i++ {
            ret *= 10
            ret += cnt[i]
        }
        return ret
    }

    m := make(map[int]bool, 30)
    for i := 0; i < 30; i++ {
        m[encode(1 << i)] = true
    }

    _, ok := m[encode(n)]
    return ok
}
