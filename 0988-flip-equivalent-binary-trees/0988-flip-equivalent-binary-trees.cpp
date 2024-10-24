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
    bool isEqual(TreeNode *node1, TreeNode *node2) {
        if (!node1 && !node2) return true;
        if (!node1 || !node2) return false;
        return node1->val == node2->val;
    }

    bool haveSameChilds(TreeNode *node1, TreeNode *node2) {
        TreeNode *left1 = node1->left, *right1 = node1->right;
        TreeNode *left2 = node2->left, *right2 = node2->right;

        return (isEqual(left1, left2) || isEqual(left1, right2)) && 
            (isEqual(right1, left2) || isEqual(right1, right2));
    }

    bool isFlipEquivalent(unordered_map<int, TreeNode*> &map1, 
        unordered_map<int, TreeNode*> &map2) {
            if (map1.size() != map2.size()) return false;
            for (auto &elem1 : map1) {
                int val1 = elem1.first;
                TreeNode *node1 = elem1.second;

                auto elem2 = map2.find(val1);
                if (elem2 == map2.end()) return false;
                TreeNode *node2 = (*elem2).second;

                if (!haveSameChilds(node1, node2)) return false;
            }
            return true;
    }
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;

        queue<TreeNode*> q1, q2;
        q1.push(root1);
        q2.push(root2);
        while (!q1.empty() && !q2.empty()) {
            unordered_map<int, TreeNode*> map1, map2;
            int k1 = q1.size(), k2 = q2.size();

            for (int i = 0; i < k1; i++) {
                TreeNode *node1 = q1.front();
                q1.pop();
                map1[node1->val] = node1;
                if (node1->left != NULL) q1.push(node1->left);
                if (node1->right != NULL) q1.push(node1->right);
            }

            for (int i = 0; i < k2; i++) {
                TreeNode *node2 = q2.front();
                q2.pop();
                map2[node2->val] = node2;
                if (node2->left != NULL) q2.push(node2->left);
                if (node2->right != NULL) q2.push(node2->right);
            }

            if (!isFlipEquivalent(map1, map2)) return false;
        }

        if (!q1.empty() || !q2.empty()) return false;
        return true;
    }
};