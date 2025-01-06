class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);
        
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) if (boxes[j] == '1') ans[i] += i - j;
            for (int j = i + 1; j < n; j++) if (boxes[j] == '1') ans[i] += j - i;
        }

        return ans;
    }
};