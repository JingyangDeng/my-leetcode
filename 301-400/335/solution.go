//考虑不交叉的情况，需利用路径的螺旋性质
//只有可能：1.越绕越大 2.越绕越小 3.先1后2
//第三种情况的衔接处需进行一些条件判断
func isSelfCrossing(distance []int) bool {
    if len(distance) <= 3 {
        return false
    }
    p := 2
    for distance[p-2] < distance[p] {
        p++
        if p == len(distance)-1 {
            return false
        }
    }
    if p == 2 {
        if distance[p+1] >= distance[p-1] {
            return true
        }
    } else if p == 3 {
        if distance[p] == distance[p-2] {
            if distance[p+1] + distance[p-3] >= distance[p-1] {
                return true
            }
        } else {
            if distance[p+1] >= distance[p-1] {
                return true
            }
        }
    } else {
        if distance[p] + distance[p-4] >= distance[p-2] {
            if distance[p+1] + distance[p-3] >= distance[p-1] {
                return true
            }
        } else {
            if distance[p+1] >= distance[p-1] {
                return true
            }
        }
    }
    p += 2
    for ; p < len(distance); p++ {
        if distance[p] >= distance[p-2] {
            return true
        }
    }
    return false
}
