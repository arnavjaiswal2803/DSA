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
    int getMinSwaps(vector<int>& original) {
        vector<int> target(original);
        sort(target.begin(), target.end());

        int swaps = 0, n = target.size();
        map<int, int> pos;
        for (int i = 0; i < n; i++) pos[original[i]] = i;

        for (int i = 0; i < n; ++i) {
            if (original[i] != target[i]) {
                swaps++;
                int targetIdx = pos[target[i]];
                pos[target[i]] = i;
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
            int qSize = q.size(), ptr = 0;
            vector<int> original(qSize);
            while (qSize--) {
                TreeNode* temp = q.front();
                q.pop();

                original[ptr++] = temp->val;

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            totalSwaps += getMinSwaps(original);
        }

        return totalSwaps;
    }
};