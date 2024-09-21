class Solution {
    void generateLexicalNumbers(int start, int limit, vector<int> &ans) {
        for (int i = 0; i <= 9; i++) {
            int currNum = start * 10 + i;
            if (currNum > limit) return;
            ans.emplace_back(currNum);
            generateLexicalNumbers(currNum, limit, ans);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int i = 1; i <= 9 && i <= n; i++) {
            ans.push_back(i);
            generateLexicalNumbers(i, n, ans);
        }
        return ans;
    }
};