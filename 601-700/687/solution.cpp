//DFS + 记忆化搜索
//注：本题有更好的解法，可以只进行一次DFS得到答案
//考虑的子问题：从root出发的最长同值路径长度
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
    unordered_map<TreeNode*, unordered_map<int, int>> dp;

    int longestRootPath(TreeNode* root, int val) {
        if(dp.count(root) && dp[root].count(val)) return dp[root][val];
        if(!root || root->val != val) return 0;
        return dp[root][val] = max(longestRootPath(root->left, val), longestRootPath(root->right, val)) + 1;
    }

public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int l = longestUnivaluePath(root->left);
        int r = longestUnivaluePath(root->right);
        int ret = longestRootPath(root->left, root->val) + longestRootPath(root->right, root->val);
        ret = max(ret, max(l, r));
        //cout << root->val << " " << ret << endl;
        return ret;
    }
};
