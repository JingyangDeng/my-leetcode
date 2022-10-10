//遍历为所有节点增加“父指针”，再进行查找
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    unordered_map<TreeNode*, TreeNode*> parent;
    void dfs(TreeNode* root){
        if(root->left){
            parent[root->left] = root;
            dfs(root->left);
        }
        if(root->right){
            parent[root->right] = root;
            dfs(root->right);
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        parent[root] = NULL;
        dfs(root);
        unordered_set<TreeNode*> s;
        for(TreeNode* curr = p; curr; curr = parent[curr]){
            s.insert(curr);
        }
        for(TreeNode* curr = q; curr; curr = parent[curr]){
            if(s.count(curr)) return curr;
        }
        return NULL;
    }
};
