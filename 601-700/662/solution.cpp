//BFS 注意满二叉树父子节点编号的关系，对节点编号计算即可
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
    int widthOfBinaryTree(TreeNode* root) {
        long long ret = 0;
        vector<pair<TreeNode*, long long>> q;
        q.push_back({root, 0});
        int lptr = 0, rptr = 1;
        while(lptr < rptr){
            int sz = rptr - lptr;
            long long high = INT_MIN, low = INT_MAX;
            for(int i = lptr; i < rptr; ++i){
                high = max(high, q[i].second);
                low = min(low, q[i].second);
            }
            ret = max(ret, high - low + 1);
            int l = lptr, r = rptr;
            for(int i = l; i < r; ++i){
                if(q[i].first->left){
                    q.push_back({q[i].first->left, (q[i].second - low) * 2 + 1});
                    ++rptr;
                }
                if(q[i].first->right){
                    q.push_back({q[i].first->right, (q[i].second - low) * 2 + 2});
                    ++rptr;
                }
                ++lptr;
            }
        }
        return ret;
    }
};
