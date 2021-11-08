//min(rows) * min(cols)
func maxCount(m int, n int, ops [][]int) int {
    minRow, minCol := m, n
    for i := 0; i < len(ops); i++ {
        if minRow > ops[i][0] {
            minRow = ops[i][0]
        }
        if minCol > ops[i][1] {
            minCol = ops[i][1]
        }
    }
    return minRow * minCol
}

