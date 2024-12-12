class Solution {
    bool isValid(int m, int n, int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    int bfs01(vector<vector<int>>& grid) {
        const int INF = 1e9;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> obstacleCount(m, vector<int>(n, INF));
        deque<pair<int, pair<int, int>>> dq;

        dq.push_front({0, {0, 0}});
        obstacleCount[0][0] = 0;

        vector<int> dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};
        while (!dq.empty()) {
            int obstacleRemoved = dq.front().first;
            int x = dq.front().second.first, y = dq.front().second.second;
            dq.pop_front();

            if (x == m - 1 && y == n - 1) return obstacleRemoved;

            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i], newY = y + dy[i];

                if (isValid(m, n, newX, newY) && 
                    obstacleRemoved + grid[newX][newY] < obstacleCount[newX][newY]) {
                        obstacleCount[newX][newY] = obstacleRemoved + grid[newX][newY];

                        if (grid[newX][newY] == 0) 
                            dq.push_front({obstacleCount[newX][newY], {newX, newY}});
                        else dq.push_back({obstacleCount[newX][newY], {newX, newY}});
                    }
            }
        }

        return obstacleCount[m - 1][n - 1];
    }

public:
    int minimumObstacles(vector<vector<int>>& grid) {
        return bfs01(grid);
    }
};