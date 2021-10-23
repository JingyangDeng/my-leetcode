//简单循环
func constructRectangle(area int) []int {
    ret := make([]int, 2)
    for i := int(math.Sqrt(float64(area))); i >= 0; i-- {
        if(area % i == 0){
            ret[0] = area / i
            ret[1] = i
            break
        }
    }
    return ret
}

