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
    void preorder(TreeNode* node, int currHeight, int &maxHeight, 
        vector<int> &nodeHeights) {
            if (node == NULL) return;

            nodeHeights[node->val] = maxHeight;
            maxHeight = max(maxHeight, currHeight);

            preorder(node->left, currHeight + 1, maxHeight, nodeHeights);
            preorder(node->right, currHeight + 1, maxHeight, nodeHeights);
        }

    void reversePreorder(TreeNode* node, int currHeight, int &maxHeight, 
        vector<int> &nodeHeights) {
            if (node == NULL) return;

            nodeHeights[node->val] = max(nodeHeights[node->val], maxHeight);
            maxHeight = max(maxHeight, currHeight);

            reversePreorder(node->right, currHeight + 1, maxHeight, nodeHeights);
            reversePreorder(node->left, currHeight + 1, maxHeight, nodeHeights);
        }
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> nodeHeights(1e5 + 1, 0);

        int maxHeight = 0;
        preorder(root, 0, maxHeight, nodeHeights);
        maxHeight = 0;
        reversePreorder(root, 0, maxHeight, nodeHeights);

        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) ans[i] = nodeHeights[queries[i]];

        return ans;
    }
};