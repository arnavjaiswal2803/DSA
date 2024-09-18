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
    void getHeight(TreeNode* root, int height, int &maxHeight) {
        if (root == NULL) return;
        maxHeight = max(maxHeight, height);

        getHeight(root->left, height + 1, maxHeight);
        getHeight(root->right, height + 1, maxHeight);
    }
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int maxHeight = 0;
        getHeight(root, 1, maxHeight);
        return maxHeight;
    }
};