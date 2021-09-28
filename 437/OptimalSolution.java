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
//执行用时：2 ms, 在所有 Java 提交中击败了100.00% 的用户
//内存消耗：38.3 MB, 在所有 Java 提交中击败了40.67% 的用户

//dfs+前缀和，遍历的同时计算以该节点为结尾的满足要求的路径数
class OptimalSolution {
    private HashMap<Integer, Integer> hMap = new HashMap<>(){{put(0, 1);}};
    private int target, ret = 0, sum = 0;

    public int pathSum(TreeNode root, int targetSum) {
        target = targetSum;
        dfs(root);
        return ret;
    }

    private void dfs(TreeNode root){
        if(root == null) return;
        sum += root.val;
        ret += hMap.getOrDefault(sum - target, 0);
        hMap.put(sum, hMap.getOrDefault(sum, 0) + 1);
        dfs(root.left);
        dfs(root.right);
        hMap.put(sum, hMap.get(sum) - 1);
        sum -= root.val;
        return;
    }
}
