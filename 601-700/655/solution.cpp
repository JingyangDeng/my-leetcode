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
    vector<vector<string>> ret;
    int m, n, height;

public:
    int get_height(TreeNode* root){
        if(!root) return 0;
        return 1 + max(get_height(root->left), get_height(root->right));
    }

    void fill_matrix(TreeNode* root, int r, int c){
        if(!root) return;
        ret[r][c] = to_string(root->val);
        fill_matrix(root->left, r+1, c-pow(2, height-r-1));
        fill_matrix(root->right, r+1, c+pow(2, height-r-1));
    }

    vector<vector<string>> printTree(TreeNode* root) {
        height = get_height(root) - 1;
        m = height + 1;
        n = pow(2, height + 1) - 1;
        ret = vector<vector<string>>(m, vector<string>(n));
        fill_matrix(root, 0, (n - 1) >> 1);
        return ret;
    }
};
