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

    TreeNode* recoverFromPreorder(string traversal) {
        vector<pair<int, int>> valDepthMap = getValDepthMap(traversal);
        int idx = 0;
        TreeNode* root = constructTree(0, valDepthMap, idx);
        return root;
    }

private:

    vector<pair<int, int>> getValDepthMap(string traversal) {
        vector<pair<int, int>> valDepthMap;
        int n = traversal.size(), dashCount = 0;

        for (int i = 0; i < n; i++) {
            if (traversal[i] == '-') dashCount++;
            else {
                int val = 0;
                while (i < n && traversal[i] != '-') {
                    val = (val * 10) + (traversal[i] - '0');
                    i++;
                }
                i--;

                valDepthMap.push_back({val, dashCount});
                dashCount = 0;
            }
        }

        return valDepthMap;
    }

    TreeNode* constructTree(int depth, vector<pair<int, int>>& valDepthMap, int& idx) {
        if (idx >= valDepthMap.size()) return NULL;
        if (valDepthMap[idx].second != depth) return NULL;

        TreeNode* node = new TreeNode(valDepthMap[idx].first);
        idx++;

        node->left = constructTree(depth + 1, valDepthMap, idx);
        if (node->left) node->right = constructTree(depth + 1, valDepthMap, idx);

        return node;
    }
};