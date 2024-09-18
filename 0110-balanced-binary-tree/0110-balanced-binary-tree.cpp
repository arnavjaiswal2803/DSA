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
    int getHeight(TreeNode* root, bool &isHeightBalanced) {
        if (root == NULL) return 0;

        int leftHeight = getHeight(root->left, isHeightBalanced);
        int rightHeight = getHeight(root->right, isHeightBalanced);

        if (abs(leftHeight - rightHeight) > 1) isHeightBalanced = false;

        return 1 + max(leftHeight, rightHeight);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool isHeightBalanced = true;
        getHeight(root, isHeightBalanced);
        return isHeightBalanced;
    }
};