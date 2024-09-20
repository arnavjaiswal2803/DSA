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
    TreeNode* insert(TreeNode *node, TreeNode *prev, int val) {
        if (node == NULL) {
            TreeNode* temp = new TreeNode(val);

            if (prev == NULL) node = temp;
            else if (val < prev->val) prev->left = temp;
            else prev->right = temp;

            return temp;
        }

        if (val < node->val) insert(node->left, node, val);
        else insert(node->right, node, val);
        return node;
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insert(root, NULL, val);
    }
};