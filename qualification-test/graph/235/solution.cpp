//在BST中，共同祖先的值应介于两节点值之间
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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        while(1){
            if(curr->val > p->val && curr->val > q->val){
                curr = curr->left; 
                continue;
            }
            if(curr->val < p->val && curr->val < q->val){
                curr = curr->right;
                continue;
            }
            break;
        }
        return curr;
    }
};
