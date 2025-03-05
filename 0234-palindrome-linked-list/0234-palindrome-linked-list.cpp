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
        if (head->next == NULL) return true;
        temp = head;
        return isLLPalindrome(head);
    }

private:
    ListNode* temp;

    bool isLLPalindrome(ListNode* node) {
        if (node == NULL) return true;

        bool result = isLLPalindrome(node->next);
        if (result) {
            if (temp->val == node->val) {
                temp = temp->next;
                return true;
            }
        }
        return false;
    }
};