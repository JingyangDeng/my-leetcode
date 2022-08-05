//DFS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> tmp_nodes;
    int tmp_level = 1;
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            return new TreeNode(val, root, nullptr);
        }
        dfs(root, depth);
        for(TreeNode* n : tmp_nodes){
            TreeNode* tmp_left = n->left;
            TreeNode* tmp_right = n->right;
            n->left = new TreeNode(val, tmp_left, nullptr);
            n->right = new TreeNode(val, nullptr, tmp_right);
        }
        return root;
    }

    void dfs(TreeNode* root, int depth){
        if(!root) return;
        if(depth == tmp_level + 1){
            tmp_nodes.emplace_back(root);
        }
        ++tmp_level;
        dfs(root->left, depth);
        dfs(root->right, depth);
        --tmp_level;
    }
};
