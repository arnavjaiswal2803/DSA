class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> prev(n);

        for (int row = 0; row < m; row++) {
            vector<int> curr(n);
            for (int col = 0; col < n; col++) {
                if (row == 0 && col == 0) curr[col] = grid[row][col];
                else if (row == 0) curr[col] = grid[row][col] + curr[col - 1];
                else if (col == 0) curr[col] = grid[row][col] + prev[col];
                else curr[col] = grid[row][col] + min(prev[col], curr[col - 1]);
            }
            prev = curr;
        }

        return prev[n - 1];
    }
};