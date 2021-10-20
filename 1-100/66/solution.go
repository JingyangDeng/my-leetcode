//模拟加法进位
func plusOne(digits []int) []int {
    p := len(digits) - 1
    digits[p] += 1
    for p >= 1 && digits[p] == 10 {
        digits[p] -= 10
        p--
        digits[p]++
    }
    if p == 0 && digits[p] == 10 {
        digits[p] -= 10
        ret := make([]int, len(digits) + 1)
        ret[0] = 1
        for i := 1; i < len(digits) + 1; i++ {
            ret[i] = digits[i-1]
        }
        return ret
    }
    return digits
}
