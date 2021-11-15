//开关次数与因数个数的奇偶性有关，只有平方数有奇数个因数。
func bulbSwitch(n int) int {
    //if n == 0 { return 0 }
    //lower, upper := 0, 1000000000
    //for lower < upper {
    //    mid := (lower + upper + 1) >> 1
    //    if mid * mid > n {
    //        upper = mid - 1
    //    } else {
    //        lower = mid
    //    }
    //}
    //return lower
    return int(math.Sqrt(float64(n) + 0.5))
}
