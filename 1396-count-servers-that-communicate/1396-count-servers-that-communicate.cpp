class Solution {
    bool hasServer(vector<vector<int>>& grid, int m, int n, int r, int c) {
        for (int row = r - 1; row >= 0; row--) if (grid[row][c]) return true;
        for (int row = r + 1; row < m; row++) if (grid[row][c]) return true;
        for (int col = c - 1; col >= 0; col--) if (grid[r][col]) return true;
        for (int col = c + 1; col < n; col++) if (grid[r][col]) return true;
        return false;
    }
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) 
                if (grid[i][j] && hasServer(grid, m, n, i, j)) ans++;
        }
        return ans;
    }
};