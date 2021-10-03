/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
//遍历搜索树得到数组，再二分递归建树
class Solution {
    ArrayList<Integer> arr = new ArrayList<>();
    public TreeNode balanceBST(TreeNode root) {
        dfs(root);
        return buildTree(0, arr.size());
    }

    private void dfs(TreeNode root){
        if(root == null) return;
        dfs(root.left);
        arr.add(root.val);
        dfs(root.right);
    }

    private TreeNode buildTree(int left, int right){
        if(left >= right) return null;
        int mid = (left + right) >> 1;
        TreeNode root = new TreeNode(arr.get(mid));
        root.left = buildTree(left, mid);
        root.right = buildTree(mid+1, right);
        return root;
    }
}
