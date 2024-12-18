class Solution {
    int lcs(string& s1, string& s2, int idx1, int idx2, vector<vector<int>>& dp) {
        if (idx1 == 0 && idx2 == 0) return s1[idx1] == s2[idx2];
        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];

        int equal = 0, unequal1 = 0, unequal2 = 0;
        if (s1[idx1] == s2[idx2]) {
            equal = 1;
            if (idx1 > 0 && idx2 > 0) equal += lcs(s1, s2, idx1 - 1, idx2 - 1, dp);
        } else {
            if (idx1 > 0) unequal1 = lcs(s1, s2, idx1 - 1, idx2, dp);
            if (idx2 > 0) unequal2 = lcs(s1, s2, idx1, idx2 - 1, dp);
        }

        return dp[idx1][idx2] = max({equal, unequal1, unequal2});
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return lcs(text1, text2, n - 1, m - 1, dp);
    }
};