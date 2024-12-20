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
    void dfs(TreeNode* leftChild, TreeNode* rightChild, bool shouldSwap) {
        if (leftChild == NULL || rightChild == NULL) return;

        if (shouldSwap) swap(leftChild->val, rightChild->val);

        dfs(leftChild->left, rightChild->right, !shouldSwap);
        dfs(leftChild->right, rightChild->left, !shouldSwap);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return root;
        dfs(root->left, root->right, true);
        return root;
    }
};