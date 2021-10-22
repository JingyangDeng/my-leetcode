//暴力Hash
func majorityElement(nums []int) []int {
    m := make(map[int]int, 50000)
    for _, n := range nums {
        m[n]++
    }
    ret := make([]int, 0)
    for k, v := range m {
        if v > len(nums) / 3 {
            ret = append(ret, k)
            if len(ret) >= 2 {
                break
            }
        }
    }
    return ret
}

