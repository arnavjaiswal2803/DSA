/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *right;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        int currLevelSum = root->val;

        q.push(root);
        while (!q.empty()) {
            int nextLevelSum = 0, k = q.size();

            for (int i = 0; i < k; i++) {
                TreeNode* node = q.front();
                q.pop();

                node->val = currLevelSum - node->val;

                int siblingSum = 0;
                if (node->left) siblingSum += node->left->val;
                if (node->right) siblingSum += node->right->val;

                if (node->left) {
                    nextLevelSum += node->left->val;
                    node->left->val = siblingSum;
                    q.push(node->left);
                }
                if (node->right) {
                    nextLevelSum += node->right->val;
                    node->right->val = siblingSum;
                    q.push(node->right);
                }
            }

            currLevelSum = nextLevelSum;
        }

        return root;
    }
};