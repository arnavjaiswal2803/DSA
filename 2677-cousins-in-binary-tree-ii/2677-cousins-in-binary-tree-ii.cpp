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
        q.push({root, NULL});
        while (!q.empty()) {
            unordered_map<TreeNode*, int> parentSum;
            int levelSum = 0, k = q.size();

            for (int i = 0; i < k; i++) {
                nodeParent temp = q.front();
                q.pop();

                levelSum += temp.node->val;
                parentSum[temp.parent] += temp.node->val;

                q.push(temp);
            }

            for (int i = 0; i < k; i++) {
                nodeParent temp = q.front();
                q.pop();

                temp.node->val = levelSum - parentSum[temp.parent];

                if (temp.node->left) 
                    q.push({temp.node->left, temp.node});
                if (temp.node->right) 
                    q.push({temp.node->right, temp.node});
            }
        }
        return root;
    }
};