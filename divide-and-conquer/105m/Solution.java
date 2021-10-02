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

//分治法判断root的位置，递归处理左右子树
class Solution {
    private HashMap<Integer, Integer> hMap = new HashMap<>();
    private int n;
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        n = preorder.length;
        for(int i = 0; i < n; i++) hMap.put(inorder[i], i);
        return merge(preorder, 0, n);
    }
    private TreeNode merge(int[] preorder, int l, int r){
        if(l == r) return null;
        TreeNode root = new TreeNode(preorder[l]);
        //事实上，循环求p是没必要的！
        int p = l+1;
        while(p < r){
            if(hMap.get(preorder[p]) < hMap.get(preorder[l])) p++;
            else break;
        }
        root.left = merge(preorder, l+1, p);
        root.right = merge(preorder, p, r);
        return root;
    }
}
