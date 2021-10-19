//n-1个数+1 <=> 1个数-1
func minMoves(nums []int) int {
    minValue := int(^uint(0) >> 1)
    for _, n := range nums {
        minValue = min(minValue, n)
    }
    ret := 0
    for _, n := range nums {
        ret += (n - minValue)
    }
    return ret
}

func min(a, b int) int {
    if(a < b) {
        return a
    }
    return b
}
