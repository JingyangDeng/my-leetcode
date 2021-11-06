//位运算 空间复杂度O(1)
func missingNumber(nums []int) int {
    ret := 0
    for i := 0; i < len(nums); i++ {
        ret ^= i
        ret ^= nums[i]
    }
    ret ^= len(nums)
    return ret
}

