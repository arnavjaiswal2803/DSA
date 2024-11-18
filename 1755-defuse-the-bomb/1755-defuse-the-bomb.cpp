class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);

        if (k == 0) return ans;
        for (int i = 0; i < n; i++) {
            int replacement = 0;
            for (int j = 1; j <= abs(k); j++) {
                int newIdx = k > 0 ? (i + j) % n : (i - j + n) % n; 
                replacement += code[newIdx];
            }
            ans[i] = replacement;
        }

        return ans;
    }
};