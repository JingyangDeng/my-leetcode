//给不同的子树编号，用(val, left, right)三元组来表示子树，建立hashmap求解
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
    // hash method copied from leetcode
    static constexpr auto tri_hash = [fn = hash<int>()](const tuple<int, int, int>& o) -> size_t {
        auto&& [x, y, z] = o;
        return (fn(x) << 24) ^ (fn(y) << 8) ^ fn(z);
    };

    unordered_map<tuple<int, int, int>, pair<int, TreeNode*>, decltype(tri_hash)> m{0, tri_hash};
    unordered_set<TreeNode*> ret;
    int id = 0;

    int dfs(TreeNode* root){
        if(!root) return 0;
        tuple<int, int, int> tri = {root->val, dfs(root->left), dfs(root->right)};
        if(m.find(tri) == m.end()){
            ++id;
            m[tri] = {id, root};
            return id;
        }
        ret.insert(m[tri].second);
        return m[tri].first;
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return {ret.begin(), ret.end()};
    }
};
