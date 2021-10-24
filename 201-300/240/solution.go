//可将矩阵看做二叉搜索树
func searchMatrix(matrix [][]int, target int) bool {
    i, j := 0, len(matrix[0])-1
    for i < len(matrix) && j >= 0 {
        if target == matrix[i][j] {return true}
        if target > matrix[i][j] {i++} else {j--}
    }
    return false
}
