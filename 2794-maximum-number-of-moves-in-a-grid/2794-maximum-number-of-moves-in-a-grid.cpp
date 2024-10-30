class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        vector<int> prev(n, 0);

        for (int col = m - 2; col >= 0; col--) {
            vector<int> curr(n, 0);
            for (int row = 0; row < n; row++) {
                int maxMoves = 0;
                for (int i = 0; i < 3; i++) {
                    vector<int> dx = {-1, 0, 1};
                    int newRow = row + dx[i], newCol = col + 1;
                    
                    if (newRow >= 0 && newRow < n && newCol < m && 
                        grid[row][col] < grid[newRow][newCol])
                            maxMoves = max(maxMoves, 1 + prev[newRow]);
                }
                curr[row] = maxMoves;

                if (col == 0) ans = max(ans, curr[row]);
            }
            prev = curr;
        }

        return ans;
    }
};