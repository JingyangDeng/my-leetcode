//哈希+模拟
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
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        ListNode* curr = head;
        int ret = 0;
        while(curr){
            while(curr && !s.count(curr->val)) curr = curr->next;
            if(!curr) break;
            while(curr && s.count(curr->val)) curr = curr->next;
            ++ret;
        }
        return ret;
    }
};
