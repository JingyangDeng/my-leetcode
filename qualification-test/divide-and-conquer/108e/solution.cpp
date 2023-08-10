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
//分治递归建树
class Solution {
private:
    TreeNode* build_tree(const vector<int>& nums, int left, int right) {
        if (left >= right)
            return nullptr;
        int mid = (left + right) >> 1;
        TreeNode* root = new TreeNode(nums[mid], build_tree(nums, left, mid), build_tree(nums, mid + 1, right));
        return root;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build_tree(nums, 0, nums.size());
    }
};
