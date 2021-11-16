//mark:
//数学观察：覆盖的条件1.面积相等，2.除4个顶点外，所有“内部顶点”都恰好出现2次或4次
func isRectangleCover(rectangles [][]int) bool {
    l, r, d, u := rectangles[0][0], rectangles[0][2], rectangles[0][1], rectangles[0][3]
    sum := 0
    m := make(map[int]int)
    for _, rect := range rectangles {
        sum += (rect[2] - rect[0]) * (rect[3] - rect[1])
        if rect[0] < l {
            l = rect[0]
        }
        if rect[2] > r {
            r = rect[2]
        }
        if rect[1] < d {
            d = rect[1]
        }
        if rect[3] > u {
            u = rect[3]
        }
        m[rect[0] + rect[1] << 20]++
        m[rect[0] + rect[3] << 20]++
        m[rect[2] + rect[1] << 20]++
        m[rect[2] + rect[3] << 20]++
    }
    //fmt.Println(l, r, d, u, sum)
    if sum != (u - d) * (r - l) {
        return false
    }
    cnt := 0
    for k, v := range m {
        if v == 1 {
            if k != l + d << 20 && k != l + u << 20 && k != r + d << 20 && k != r + u << 20 {
                return false
            }
            cnt++
            continue
        }
        if v != 2 && v != 4 {
            return false
        }
    }
    return cnt == 4
}
