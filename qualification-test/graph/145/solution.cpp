//使用栈的后序遍历非递归实现
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        TreeNode* node = root;
        int addr = 1;
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        
    entry:
        node = st.top().first; addr = st.top().second;
        st.pop();
        if(!node) {
            st.push({node, addr});
            goto exit;
        } else {
            st.push({node, addr});
            node = node->left;
            st.push({node, 2});
            goto entry;
        }

    exit:
        node = st.top().first; addr = st.top().second;
        st.pop();
        switch(addr){
            case 1: {
                return ret;
            }
            case 2: {
                goto L1;
            }
            case 3: {
                goto L2;
            }
        }

    L1:
        node = st.top().first; addr = st.top().second;
        node = node->right;
        st.push({node, 3});
        goto entry;
    
    L2:
        node = st.top().first; addr = st.top().second;
        ret.push_back(node->val);
        goto exit;
    
        return ret;
    }
};
