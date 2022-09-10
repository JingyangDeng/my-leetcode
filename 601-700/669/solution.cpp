//递归修剪子树，也可以直接对trimBST递归
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        root = trimLowBST(root, low);
        root = trimHighBST(root, high);
        return root;
    }

    TreeNode* trimLowBST(TreeNode* root, int low) {
        if(!root) return root;
        if(root->val < low) return trimLowBST(root->right, low);
        root->left = trimLowBST(root->left, low);
        return root;
    }

    TreeNode* trimHighBST(TreeNode* root, int high) {
        if(!root) return root;
        if(root->val > high) return trimHighBST(root->left, high);
        root->right = trimHighBST(root->right, high);
        return root;
    }
};
