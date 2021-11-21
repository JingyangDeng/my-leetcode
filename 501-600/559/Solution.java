/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

// DFS
class Solution {
    public int maxDepth(Node root) {
        if(root == null) return 0;
        return dfs(root);
    }

    private int dfs(Node root){
        int ret = 0;
        for(int i = 0; i < root.children.size(); ++i){
            ret = Math.max(ret, dfs(root.children.get(i)));
        }
        ret++;
        return ret;
    }
}
