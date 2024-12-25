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
    void preorder(TreeNode* node, vector<int>& maxRowValues, int row) {
        if (!node) return;

        if (maxRowValues.size() > row) 
            maxRowValues[row] = max(maxRowValues[row], node->val);
        else maxRowValues.push_back(node->val);

        preorder(node->left, maxRowValues, row + 1);
        preorder(node->right, maxRowValues, row + 1);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};

        vector<int> maxRowValues;
        preorder(root, maxRowValues, 0);
        return maxRowValues;        
    }
};