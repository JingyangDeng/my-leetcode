//直接将节点插入树中
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root->val < val){
            return new TreeNode(val, root, nullptr);
        }
        TreeNode* cur = root;
        while(cur->right){
            if(cur->right->val > val) cur = cur->right;
            else break;
        }
        if(cur->right){
            TreeNode* tmp = cur->right;
            cur->right = new TreeNode(val, tmp, nullptr);
        } else {
            cur->right = new TreeNode(val);
        }
        return root;
    }
};
