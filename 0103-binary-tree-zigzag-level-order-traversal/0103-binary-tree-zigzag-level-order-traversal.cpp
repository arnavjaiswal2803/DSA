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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool isLeftToRight = true;
        while (!q.empty()) {
            int qSize = q.size();
            vector<int> level(qSize);

            for (int i = 0; i < qSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                isLeftToRight ? level[i] = node->val : 
                    level[qSize - i - 1] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans.push_back(level);
            isLeftToRight = !isLeftToRight;
        }

        return ans;
    }
};