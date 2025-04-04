/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        calculateDiameter(root, &maxDia);
        return maxDia;
    }

private:
    int calculateDiameter(TreeNode* root, int* maxDia) {
        if (root == NULL) return 0;

        int leftDia = calculateDiameter(root->left, maxDia);
        int rightDia = calculateDiameter(root->right, maxDia);

        *maxDia = max({*maxDia, leftDia, rightDia, leftDia + rightDia});

        return 1 + max(leftDia, rightDia);
    }
};