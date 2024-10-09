class Solution {
    int minPathSum(int row, int col, vector<vector<int>> &grid, 
        vector<vector<int>> &dp) {
            if (row < 0 || col < 0) return INT_MAX;
            if (row == 0 && col == 0) return grid[row][col];
            if (dp[row][col] != -1) return dp[row][col];

            return dp[row][col] = grid[row][col] + 
                min(minPathSum(row - 1, col, grid, dp), 
                    minPathSum(row, col - 1, grid, dp));
        }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return minPathSum(m - 1, n - 1, grid, dp);
    }
};