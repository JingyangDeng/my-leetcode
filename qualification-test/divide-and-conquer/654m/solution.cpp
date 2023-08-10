//分治递归构造
//注：此题有单调栈O(n)解法
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
    TreeNode* constructMaximumBinaryTreeRecursive(vector<int>& nums, int l, int r){
        if(l >= r) return nullptr;
        int pos = max_element(nums.begin() + l, nums.begin() + r) - nums.begin();
        TreeNode* left = constructMaximumBinaryTreeRecursive(nums, l, pos);
        TreeNode* right = constructMaximumBinaryTreeRecursive(nums, pos + 1, r);
        return new TreeNode(nums[pos], left, right);
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTreeRecursive(nums, 0, nums.size());
    }
};
