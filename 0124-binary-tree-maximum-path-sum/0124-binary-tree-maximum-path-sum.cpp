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

        int left = maxPathSum(root->left, maxSum);
        int right = maxPathSum(root->right, maxSum);

        int sum = root->val;
        if (left > 0) sum += left;
        if (right > 0) sum += right;
        maxSum = max(maxSum, sum);

        return root->val + max({0, left, right});
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = root->val;
        maxPathSum(root, maxSum);
        return maxSum;
    }
};