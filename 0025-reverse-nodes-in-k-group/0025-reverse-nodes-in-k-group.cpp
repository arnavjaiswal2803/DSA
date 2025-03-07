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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = findLengthOfLinkedList(head);
        return reverseKGroup(head, k, n);
    }

private:
    ListNode* reverseKGroup(ListNode* head, int k, int n) {
        if (head == NULL || k > n) return head;

        ListNode *curr = head, *prev = NULL, *nextGroup = NULL;
        for (int i = 0; i < k; i++) {
            ListNode* next = curr->next;
            if (i == k - 1) nextGroup = next;

            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = reverseKGroup(nextGroup, k, n - k);
        return prev;
    }

    int findLengthOfLinkedList(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }
};