//Kanade算法，考虑以i为结尾的最大连续和，动态规划
func maxSubArray(nums []int) int {
    max := -100010
    curMax := -100010
    for _, n := range nums {
        if curMax > 0 {curMax += n} else {curMax = n}
        if curMax > max {max = curMax}
    }
    return max
}
