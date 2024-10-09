class Solution {
    int minSum(int row, int col, int maxCol, vector<vector<int>> &matrix, 
        vector<vector<int>> &dp) {
            if (col < 0 || col > maxCol) return INT_MAX;
            if (row == 0) return matrix[row][col];
            if (dp[row][col] != 1e9) return dp[row][col]; 

            return dp[row][col] = matrix[row][col] + min({
                minSum(row - 1, col - 1, maxCol, matrix, dp), 
                minSum(row - 1, col, maxCol, matrix, dp), 
                minSum(row - 1, col + 1, maxCol, matrix, dp)
            });
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 1e9));
        int ans = INT_MAX;
        for (int col = 0; col < n; col++) 
            ans = min(ans, minSum(n - 1, col, n - 1, matrix, dp));
        return ans;
    }
};