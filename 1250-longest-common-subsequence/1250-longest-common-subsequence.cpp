class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        for (int idx1 = 0; idx1 < n; ++idx1) {
            for (int idx2 = 0; idx2 < m; ++idx2) {
                if (idx1 == 0 && idx2 == 0) dp[idx1][idx2] = s1[idx1] == s2[idx2];
                else {
                    int equal = 0, unequal1 = 0, unequal2 = 0;
                    if (s1[idx1] == s2[idx2]) {
                        equal = 1;
                        if (idx1 > 0 && idx2 > 0) equal += dp[idx1 - 1][idx2 - 1];
                    } else {
                        if (idx1 > 0) unequal1 = dp[idx1 - 1][idx2];
                        if (idx2 > 0) unequal2 = dp[idx1][idx2 - 1];
                    }

                    dp[idx1][idx2] = max({equal, unequal1, unequal2});
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};