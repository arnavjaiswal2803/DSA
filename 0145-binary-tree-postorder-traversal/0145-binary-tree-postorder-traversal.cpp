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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if (root == NULL) return postorder;

        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (!st.empty() || curr != NULL) {
            if (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* temp = st.top();
                if (temp->right != NULL) {
                    curr = temp->right;
                } else {
                    st.pop();

                    postorder.push_back(temp->val);

                    while (!st.empty() && st.top()->right == temp) {
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    }
                }
            }
        }

        return postorder;
    }
};