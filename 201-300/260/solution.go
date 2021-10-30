//mark
//1.全部异或起来，得到xor = x ^ y
//2.显然xor != 0, 因为x != y
//3.求xor的最低位1的位置l: xor & (-xor)，x和y在该位上一个为1，一个为0
//4.将n个数按第l位是否为1分组异或
//此算法时间复杂度O(n)，空间复杂度O(1)
func singleNumber(nums []int) []int {
    xor := 0
    for _, n := range nums {
        xor ^= n
    }
    lowbit := xor & (-xor)
    ret := make([]int, 2)
    for _, n := range nums {
        if (lowbit & n) > 0 {
            ret[0] ^= n
        } else {
            ret[1] ^= n
        }
    }
    return ret
}

