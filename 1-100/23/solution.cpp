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
 //优先队列维护k个当前指针的值
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(!n) return nullptr;

        vector<ListNode*> curs(n);
        priority_queue<pair<int, int>> pq;
        ListNode* res = nullptr;
        ListNode* ptr = nullptr;

        for(int i = 0; i < n; ++i){
            curs[i] = lists[i];
            if(!curs[i]) continue;
            pq.push({-curs[i]->val, -i});
        }

        while(!pq.empty()) {
            auto [val, k] = pq.top();
            if(!res) {
                res = curs[-k];
                ptr = res;
            } else {
                ptr->next = curs[-k];
                ptr = ptr->next;
            }

            pq.pop();
            curs[-k] = curs[-k]->next;
            
            if(curs[-k]) {
                pq.push({-curs[-k]->val, k});
            }
        }
        return res;
    }
};
