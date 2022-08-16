//DFS，可继续优化
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
    unordered_map<TreeNode*, int> level;
    int max_level = 0;    

public:
    int deepestLeavesSum(TreeNode* root) {
        int ret = 0;
        dfs(root, 0);
        for(auto [n, lv] : level){
            if(lv == max_level) ret += n->val;
        }
        return ret;
    }

    void dfs(TreeNode* root, int depth){
        if(!root) return;
        level[root] = depth;
        max_level = max(max_level, depth);
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
};
