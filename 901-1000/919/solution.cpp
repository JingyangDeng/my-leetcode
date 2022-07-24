//根据当前树节点数量的二进制表示推测插入节点的位置
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
class CBTInserter {
public:
    TreeNode* root;
    int num;
    CBTInserter(TreeNode* root) {
        this->root = root;
        num = count(root);
    }

    int count(TreeNode* root) {
        if(!root) return 0;
        return count(root->right) + count(root->left) + 1;
    }
    
    int insert(int val) {
        int pos = 10;
        int tmp = num+1;
        TreeNode* cur = root;
        while(!(tmp & (1 << pos))) --pos;
        for(int i = pos-1; i > 0; --i){
            if((tmp & (1 << i))){
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }
        if(tmp & 1){
            cur->right = new TreeNode(val);
        } else {
            cur->left = new TreeNode(val);
        }
        ++num;
        return cur->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
