//递归求解，containsOneNode函数求root中是否包含p，q中至少一个节点
//最近公共祖先parent一定满足：要么1.parent=p或q且有一颗子树包含p或q，要么2.parent的左右两颗子树各包含一个p，q中节点
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
    TreeNode* ret;
    bool containsOneNode(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return false;
        bool l = containsOneNode(root->left, p, q);
        bool r = containsOneNode(root->right, p, q);
        if((l && r) || ((root->val == p->val || root->val == q->val) && (l || r))) ret = root;
        return l || r || root->val == p->val || root->val == q->val;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        containsOneNode(root, p, q);
        return ret;
    }
};
