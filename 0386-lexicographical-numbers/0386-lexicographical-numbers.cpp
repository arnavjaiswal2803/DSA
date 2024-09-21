class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans(n);
        vector<string> numStr(n);
        for (int i = 1; i <= n; i++) numStr[i - 1] = to_string(i);
        sort(numStr.begin(), numStr.end());
        for (int i = 0; i < n; i++) ans[i] = stoi(numStr[i]);
        return ans;
    }
};