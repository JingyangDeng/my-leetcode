// 二分答案
func isPerfectSquare(num int) bool {
    l, r := 0, 1 << 16
    for l < r {
        tmp := (l + r + 1) >> 1
        if tmp * tmp <= num {
            l = tmp
        } else {
            r = tmp - 1
        }
    }
    return l * l == num
}
