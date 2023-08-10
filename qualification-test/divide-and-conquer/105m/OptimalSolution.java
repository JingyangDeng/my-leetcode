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
//执行用时：1 ms, 在所有 Java 提交中击败了99.31% 的用户
//内存消耗：38.4 MB, 在所有 Java 提交中击败了61.18% 的用户
class Solution {
    private HashMap<Integer, Integer> hMap = new HashMap<>();
    private int n;
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        n = preorder.length;
        for(int i = 0; i < n; i++) hMap.put(inorder[i], i);
        return merge(preorder, 0, n, 0);
    }
    private TreeNode merge(int[] preorder, int l, int r, int l2){
        if(l >= r) return null;
        TreeNode root = new TreeNode(preorder[l]);
        int rootPos = hMap.get(root.val);
        int mid = l + rootPos - l2 + 1;
        root.left = merge(preorder, l+1, mid, l2);
        root.right = merge(preorder, mid, r, rootPos+1);
        return root;
    }
}
