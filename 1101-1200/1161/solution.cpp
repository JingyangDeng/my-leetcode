//BFS
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
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        int mmax = INT_MIN;
        int ret = 0;
        int level = 0;
        int sum = INT_MIN;
        q.push({root, 1});
        while(!q.empty()){
            auto [node, lv] = q.front();
            q.pop();
            if(!node) continue;
            if(lv > level){
                if(mmax < sum){
                    mmax = sum;
                    ret = level;
                }
                sum = 0;
                ++level;
            }
            sum += node->val;
            q.push({node->left, lv+1});
            q.push({node->right, lv+1});
        }
        if(mmax < sum){
            mmax = sum;
            ret = level;
        }
        return ret;
    }
};
