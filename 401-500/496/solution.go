//单调栈
//执行用时：0 ms, 在所有 Go 提交中击败了100.00% 的用户
//内存消耗：3.3 MB, 在所有 Go 提交中击败了60.83% 的用户 
func nextGreaterElement(nums1 []int, nums2 []int) []int {
    dic := make(map[int]int, 1000)
    st := make([]int, 1000)
    p := -1
    for i := 0; i < len(nums2); i++ {
        for p >= 0 {
            top := st[p]
            if nums2[i] <= top {
                p++
                st[p] = nums2[i]
                break
            }
            dic[top] = nums2[i]
            p--
        }
        if(p < 0) {
            p++
            st[p] = nums2[i]
        }
    }
    for i := 0; i < len(nums1); i++ {
        if n, ok := dic[nums1[i]]; !ok {
            nums1[i] = -1
        } else {
            nums1[i] = n
        }
    }
    return nums1
}
