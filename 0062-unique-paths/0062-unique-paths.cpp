class Solution {
    int countUniquePaths(int row, int col, vector<vector<int>> &dp) {
        if (row == 0 || col == 0) return 1;
        if (dp[row][col] != -1) return dp[row][col];

        return dp[row][col] = countUniquePaths(row - 1, col, dp) + 
            countUniquePaths(row, col - 1, dp);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countUniquePaths(m - 1, n - 1, dp);
    }
};