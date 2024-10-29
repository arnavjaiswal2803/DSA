class Solution {
    int moves(int row, int col, int n, int m, 
        vector<vector<int>> &grid, vector<vector<int>> &dp) {
            if (dp[row][col] != -1) return dp[row][col];

            vector<int> dx = {-1, 0, 1};
            int maxMoves = 0;
            for (int i = 0; i < 3; i++) {
                int newRow = row + dx[i], newCol = col + 1;
                
                if (newRow >= 0 && newRow < n && newCol < m && 
                    grid[row][col] < grid[newRow][newCol]) {
                        maxMoves = max(maxMoves, 
                            1 + moves(newRow, newCol, n, m, grid, dp));
                    }
            }

            return dp[row][col] = maxMoves;
        }

public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            ans = max(ans, moves(i, 0, n, m, grid, dp));
        }
        return ans;
    }
};