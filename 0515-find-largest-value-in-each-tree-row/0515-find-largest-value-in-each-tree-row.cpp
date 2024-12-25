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
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        
        queue<TreeNode*> q;
        vector<int> maxRowValues;

        q.push(root);
        while (!q.empty()) {
            int qSize = q.size(), currRowMaxVal = INT_MIN;
            
            while (qSize--) {
                TreeNode* node = q.front();
                q.pop();

                currRowMaxVal = max(currRowMaxVal, node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            maxRowValues.push_back(currRowMaxVal);
        }
        
        return maxRowValues;
    }
};