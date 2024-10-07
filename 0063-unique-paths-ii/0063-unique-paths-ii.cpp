class Solution {
    int getPaths(int row, int col, vector<vector<int>> &obstacleGrid, 
        vector<vector<int>> &dp) {
            if (row < 0 || col < 0) return 0;
            if (obstacleGrid[row][col] == 1) return 0;
            if (row == 0 && col == 0) return 1;
            if (dp[row][col] != -1) return dp[row][col];

            return dp[row][col] = getPaths(row - 1, col, obstacleGrid, dp) + 
                getPaths(row, col - 1, obstacleGrid, dp);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return getPaths(m - 1, n - 1, obstacleGrid, dp);
        return dp[m - 1][n - 1];
    }
};