//要点在于找到根节点，再递归构造左右子树
//可修改代码以略去构造临时vector需要的时间
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(!inorder.size()) return nullptr;
        int root = postorder[postorder.size() - 1];
        auto p = find(inorder.begin(), inorder.end(), root);
        int n_left = p - inorder.begin();
        int n_right = inorder.end() - p - 1;
        vector<int> inorder_left(inorder.begin(), p);
        vector<int> inorder_right(p + 1, inorder.end());
        vector<int> postorder_left(postorder.begin(), postorder.begin() + n_left);
        vector<int> postorder_right(postorder.begin() + n_left, postorder.end() - 1);
        return new TreeNode(root, buildTree(inorder_left, postorder_left), buildTree(inorder_right, postorder_right));
    }
};
