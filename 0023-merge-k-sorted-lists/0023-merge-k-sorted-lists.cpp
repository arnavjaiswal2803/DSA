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
        vector<int> ans;
        int n = lists.size();

        for (int i = 0; i < n; i++) {
            ListNode* node = lists[i];
            while (node != NULL) {
                ans.push_back(node->val);
                node = node->next;
            }
        }
        if (ans.size() == 0) return NULL;
        int m = ans.size();

        sort(ans.begin(), ans.end());

        ListNode* newHead = new ListNode(ans[0]);
        ListNode* temp = newHead;
        for (int i = 1; i < m; i++) {
            temp->next = new ListNode(ans[i]);
            temp = temp->next;
        }

        return newHead;
    }
};