class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (row == 0 && col == 0) dp[row][col] = grid[row][col];
                else if (row == 0) dp[row][col] = grid[row][col] + dp[row][col - 1];
                else if (col == 0) dp[row][col] = grid[row][col] + dp[row - 1][col];
                else dp[row][col] = 
                    grid[row][col] + min(dp[row - 1][col], dp[row][col - 1]);
            }
        }

        return dp[m - 1][n - 1];
    }
};