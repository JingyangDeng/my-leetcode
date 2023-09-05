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
//若root左右子树高度相等，则其最深叶节点的最近公共祖先=root
class Solution {
    int get_height(TreeNode* root) {
        if(!root) return 0;
        return 1 + max(get_height(root->left), get_height(root->right));
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int l = get_height(root->left);
        int r = get_height(root->right);
        if(l == r) return root;
        if(l < r) return lcaDeepestLeaves(root->right);
        return lcaDeepestLeaves(root->left);
    }
};
