class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
                if (i == 0 || j == 0) dp[i][j] = 0;
                else {
                    if (str1[i - 1] == str2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                    else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        string revAns = "";
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                revAns.push_back(str1[i - 1]);
                i--, j--;
            }
            else {
                dp[i][j - 1] > dp[i - 1][j] ? revAns.push_back(str2[--j]) : revAns.push_back(str1[--i]);
            }
        }
        
        while (i > 0) revAns.push_back(str1[--i]);
        while (j > 0) revAns.push_back(str2[--j]);
        
        reverse(revAns.begin(), revAns.end());
        
        return revAns;
    }
};