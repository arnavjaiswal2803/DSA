class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, 1e9));

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (row == 0) dp[row][col] = matrix[row][col];
                else {
                    int prevSum = dp[row - 1][col];
                    if (col > 0) prevSum = min(prevSum, dp[row - 1][col - 1]);
                    if (col < n - 1) prevSum = min(prevSum, dp[row - 1][col + 1]);

                    dp[row][col] = matrix[row][col] + prevSum;
                }
                if (row == n - 1) ans = min(ans, dp[n - 1][col]);
            }
        }

        return ans;
    }
};