/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 //中序遍历
func kthSmallest(root *TreeNode, k int) int {
    ret, cnt := 0, 0
    
    var dfs func(*TreeNode)
    dfs = func(root *TreeNode) {
        if(root == nil) {
            return
        }
        dfs(root.Left)
        cnt++
        if cnt == k {
            ret = root.Val
            return
        }
        dfs(root.Right)
        return
    }

    dfs(root)
    return ret
}
