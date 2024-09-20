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
    int maxPathSum(TreeNode *root, int &maxSum) {
        if (root == NULL) return 0;
        int left = max(0, maxPathSum(root->left, maxSum));
        int right = max(0, maxPathSum(root->right, maxSum));
        maxSum = max(maxSum, root->val + left + right);
        return root->val + max(left, right);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = root->val;
        maxPathSum(root, maxSum);
        return maxSum;
    }
};