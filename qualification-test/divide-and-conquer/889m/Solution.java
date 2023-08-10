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
//分治法，通过查hash表推断代表左子树和右子树的区间 T(n)=2T(n/2)+O(1) -> T(n)=O(n)，预处理O(n)
class Solution {
    private HashMap<Integer, Integer> hMap = new HashMap<>();
    private int n;
    public TreeNode constructFromPrePost(int[] preorder, int[] postorder) {
        n = preorder.length;
        for(int i = 0; i < n; i++) hMap.put(postorder[i], i);
        return buildTree(preorder, 0, n-1, 0);
    }

    private TreeNode buildTree(int[] preorder, int lpre, int rpre, int lpost){
        if(rpre < lpre) return null;
        if(rpre == lpre) return new TreeNode(preorder[lpre]);
        if(rpre == lpre + 1) return new TreeNode(preorder[lpre], new TreeNode(preorder[lpre+1]), null);
        int pos = hMap.get(preorder[lpre+1]);
        int lcnt = pos - lpost + 1;
        return new TreeNode(preorder[lpre], buildTree(preorder, lpre+1, lpre+lcnt, lpost), buildTree(preorder, lpre+lcnt+1, rpre, pos+1));
    }
}
