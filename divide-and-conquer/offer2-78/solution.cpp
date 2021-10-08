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
//分治法求解
class Solution {
private:
    ListNode* merge(const vector<ListNode*>& lists, int left, int right) {
        if (left + 1 == right)
            return lists[left];
        int mid = (left + right + 1) >> 1;
        ListNode* head1 = merge(lists, left, mid);
        ListNode* head2 = merge(lists, mid, right);
        if (head1 == nullptr)
            return head2;
        if (head2 == nullptr)
            return head1;
        ListNode* ret = nullptr;
        if (head1->val < head2->val) {
            ret = head1;
            head1 = head1->next;
        } else {
            ret = head2;
            head2 = head2->next;
        }
        ListNode* cur = ret;
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val < head2->val) {
                cur->next = head1;
                head1 = head1->next;
            } else {
                cur->next = head2;
                head2 = head2->next;
            }
            cur = cur->next;
        }
        if (head1 == nullptr)
            cur->next = head2;
        else
            cur->next = head1;
        return ret;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        return merge(lists, 0, lists.size());
    }
};
