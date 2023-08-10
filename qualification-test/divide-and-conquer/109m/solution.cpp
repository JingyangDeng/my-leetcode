/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
//分治，递归建立左右子树
class Solution {
private:
    TreeNode* build_tree(ListNode* head, int cnt) {
        if (cnt == 0)
            return nullptr;
        if (cnt == 1)
            return new TreeNode(head->val);
        int pos = 1 + (cnt >> 1);
        ListNode* cur = head;
        for (int i = 0; i < pos - 2; i++)
            cur = cur->next;
        ListNode* center = cur->next;
        cur->next = nullptr;
        cur = center->next;
        return new TreeNode(center->val, build_tree(head, pos - 1), build_tree(cur, cnt - pos));
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        int cnt = 0;
        ListNode* cur = head;
        while (cur) {
            cnt++;
            cur = cur->next;
        }
        return build_tree(head, cnt);
    }
};
