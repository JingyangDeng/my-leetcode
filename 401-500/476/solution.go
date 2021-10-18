func findComplement(num int) int {
    ret := 0
    n := 0
    for num != 0 {
        k := (num ^ 1) & 1
        k <<= n
        n++
        num >>= 1
        ret |= k 
    }
    return ret
}
