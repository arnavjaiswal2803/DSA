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
    struct nodeParent {
        TreeNode* node;
        TreeNode* parent;
    };
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<nodeParent> q;
        unordered_map<TreeNode*, int> parentSum;
        parentSum[NULL] = root->val;
        int currLevelSum = root->val;

        q.push({root, NULL});
        while (!q.empty()) {
            int nextLevelSum = 0, k = q.size();

            for (int i = 0; i < k; i++) {
                nodeParent temp = q.front();
                q.pop();

                temp.node->val = currLevelSum - parentSum[temp.parent];

                if (temp.node->left) {
                    nextLevelSum += temp.node->left->val;
                    parentSum[temp.node] += temp.node->left->val;
                    q.push({temp.node->left, temp.node});
                }
                if (temp.node->right) {
                    nextLevelSum += temp.node->right->val;
                    parentSum[temp.node] += temp.node->right->val;
                    q.push({temp.node->right, temp.node});
                }
            }

            currLevelSum = nextLevelSum;
        }

        return root;
    }
};