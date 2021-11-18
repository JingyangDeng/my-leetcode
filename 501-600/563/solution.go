/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 //dfs
func findTilt(root *TreeNode) int {
    _, tilt := dfs(root)
    return tilt
}

func dfs(root *TreeNode) (int, int) {
    if root == nil {
        return 0, 0
    }
    lSum, lTilt := dfs(root.Left)
    rSum, rTilt := dfs(root.Right)
    return lSum + rSum + root.Val, lTilt + rTilt + absInt(lSum - rSum)
}

func absInt(x int) int {
    if x >= 0 {
        return x
    }
    return -x
}

