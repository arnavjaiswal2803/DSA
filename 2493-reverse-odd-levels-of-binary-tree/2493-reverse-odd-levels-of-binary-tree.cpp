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
    bool isOddLevel(int level) { return level & 1; };
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> values;
        int level = 0;

        q.push(root);
        while (!q.empty()) {
            int qSize = q.size();
            while (qSize--) {
                TreeNode* temp = q.front();
                q.pop();

                if (isOddLevel(level)) {
                    temp->val = values.back();
                    values.pop_back();
                }

                if (temp->left != NULL) {
                    if (!isOddLevel(level)) values.push_back(temp->left->val);
                    q.push(temp->left);
                }
                if (temp->right != NULL) {
                    if (!isOddLevel(level)) values.push_back(temp->right->val);
                    q.push(temp->right);
                }
            } 
            level++;
        }

        return root;
    }
};