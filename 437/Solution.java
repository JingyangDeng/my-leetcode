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
//dfs，但代码写得过于愚蠢...
//主要是为了去重终点不为叶子节点的路径，引入了大量奇怪的数据结构。
class Solution {
    private ArrayList<TreeNode> arr = new ArrayList<>();
    private HashMap<Integer, HashSet<Integer>> hMap = new HashMap<>();
    private HashSet<Pair<TreeNode, TreeNode>> pairs = new HashSet<>();
    private int target;

    public int pathSum(TreeNode root, int targetSum) {
        if(root == null) return 0;
        target = targetSum;
        dfs(root);
        return pairs.size();
    }

    private void dfs(TreeNode root){
        boolean hasLeft = root.left != null;
        boolean hasRight = root.right != null;
        arr.add(root);
        if(hasLeft) dfs(root.left);
        if(hasRight) dfs(root.right);
        if(!hasLeft && !hasRight) count();
        arr.remove(arr.size()-1);
    }

    private void count(){
        int sum = 0;
        hMap.clear();
        hMap.put(0, new HashSet<Integer>(){{add(-1);}});
        HashSet<Integer> hSet;
        for(int i = 0; i < arr.size(); i++){
            sum += arr.get(i).val;
            hSet = hMap.getOrDefault(sum - target, new HashSet<Integer>());
            for(int index : hSet){
                pairs.add(new Pair<>(arr.get(index+1), arr.get(i)));
            }
            hSet = hMap.getOrDefault(sum, new HashSet<Integer>());
            hSet.add(i);
            hMap.put(sum, hSet);
        }
        //System.out.println(hMap);
    }
}
