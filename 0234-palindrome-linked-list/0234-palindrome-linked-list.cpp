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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *newHead = reverseLL(slow->next);
        ListNode *node1 = head, *node2 = newHead;
        bool ans = true;
        while (node1 != NULL && node2 != NULL) {
            if (node1->val != node2->val) {
                ans = false;
                break;
            }
            node1 = node1->next;
            node2 = node2->next;
        }

        reverseLL(newHead);

        return ans;
    }

private:
    ListNode* reverseLL(ListNode* head) {
        ListNode *curr = head, *prev = NULL;
        while (curr != NULL) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};