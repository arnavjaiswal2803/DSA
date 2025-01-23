class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<vector<int>> dupGrid(grid);

        for (int row = 0; row < m; row++) {
            bool hasServer = false;
            int count = 0;
            for (int col = 0; col < n; col++) {
                if (dupGrid[row][col] == 1) {
                    count++;
                } else if (dupGrid[row][col] == 2) {
                    hasServer = true;
                }
            }
            if (count > 1 || hasServer) {
                ans += count;
                for (int col = 0; col < n; col++) 
                    if (dupGrid[row][col]) dupGrid[row][col] = 2;
            }
        }
        
        for (int col = 0; col < n; col++) {
            bool hasServer = false;
            int count = 0;
            for (int row = 0; row < m; row++) {
                if (dupGrid[row][col] == 1) {
                    count++;
                } else if (dupGrid[row][col] == 2) {
                    hasServer = true;
                }
            }
            if (count > 1 || hasServer) ans += count;
        }

        return ans;
    }
};