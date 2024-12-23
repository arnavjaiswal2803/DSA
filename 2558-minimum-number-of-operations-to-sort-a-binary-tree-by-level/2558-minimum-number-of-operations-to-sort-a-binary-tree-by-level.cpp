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
    int getMinSwaps(vector<int>& original, int n) {
        int swaps = 0;
        vector<int> target(original);

        sort(target.begin(), target.end());

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) pos[original[i]] = i;

        for (int i = 0; i < n; ++i) {
            if (original[i] != target[i]) {
                swaps++;

                int targetIdx = pos[target[i]];
                pos[original[i]] = targetIdx;
                swap(original[i], original[targetIdx]);
            }
        }

        return swaps;
    }
public:
    int minimumOperations(TreeNode* root) {
        int totalSwaps = 0;
        queue<TreeNode*> q;

        q.push(root);
        while (!q.empty()) {
            int qSize = q.size();
            vector<int> original(qSize);

            for (int i = 0; i < qSize; i++) {
                TreeNode* temp = q.front();
                q.pop();

                original[i] = temp->val;

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            totalSwaps += getMinSwaps(original, qSize);
        }

        return totalSwaps;
    }
};