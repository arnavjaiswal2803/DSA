class Solution {
    bool isValid(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& vis) {
        return x >= 0 && x < grid.size() && y >= 0 && y < grid.size() && 
            grid[x][y] == 0 && !vis[x][y];
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, int>> q;

        q.push({0, 0});
        vis[0][0] = true;

        int len = 1;
        vector<int> dx = {0, 1, 0, -1, -1, 1, -1, 1}, dy = {-1, 0, 1, 0, -1, -1, 1, 1};
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                int x = q.front().first, y = q.front().second;
                q.pop();

                if (x == n - 1 && y == n - 1) return len;

                for (int i = 0; i < 8; i++) {
                    int newX = x + dx[i], newY = y + dy[i];
                    if (isValid(grid, newX, newY, vis)) {
                        q.push({newX, newY});
                        vis[newX][newY] = true;
                    }
                }
            }
            len++;
        }

        return -1;
    }
};