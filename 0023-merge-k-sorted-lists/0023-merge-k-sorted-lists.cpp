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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        typedef pair<int, ListNode*> pil;

        priority_queue<pil, vector<pil>, greater<pil>> pq;
        int n = lists.size();
        ListNode dummy;
        ListNode* temp = &dummy;

        for (int i = 0; i < n; i++) 
            if (lists[i] != NULL) pq.push({lists[i]->val, lists[i]});

        while (!pq.empty()) {
            ListNode* node = pq.top().second;

            temp->next = node;
            temp = temp->next;
            
            pq.pop();
            if (node->next != NULL) pq.push({node->next->val, node->next});
        }

        return dummy.next;
    }
};