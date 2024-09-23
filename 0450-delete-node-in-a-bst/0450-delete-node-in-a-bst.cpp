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
class Solution {
    TreeNode* deleteNode(TreeNode *toDelete, TreeNode* prev) {
        TreeNode* temp = toDelete;
        if (temp->left != NULL) {
            prev = temp;
            temp = temp->left;
            while (temp->right != NULL) {
                prev = temp;
                temp = temp->right;
            }
        } else if (temp->right != NULL) {
            prev = temp;
            temp = temp->right;
            while (temp->left != NULL) {
                prev = temp;
                temp = temp->left;
            }
        }
        
        if (prev != NULL) {
            if (prev->left == temp) {
                prev->left = temp->left != NULL ? temp->left : temp->right;
            } else if (prev->right == temp) {
                prev->right = temp->right != NULL ? temp->right : temp->left;
            }
        }

        swap(toDelete->val, temp->val);
        delete temp;
        
        return prev == NULL && temp == toDelete ? NULL : toDelete;
    }

    TreeNode* searchAndDelete(TreeNode* root, int key) {
        TreeNode *temp = root, *prev = NULL;
        while (temp != NULL) {
            if (temp->val == key) {
                if (deleteNode(temp, prev) == NULL) return NULL;
                break;
            } else if (temp->val < key) {
                prev = temp;
                temp = temp->right;
            } else {
                prev = temp;
                temp = temp->left;
            }
        }
        return root;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        return searchAndDelete(root, key);
    }
};