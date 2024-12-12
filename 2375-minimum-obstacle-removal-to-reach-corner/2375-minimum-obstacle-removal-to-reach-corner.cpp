class Solution {
    bool isValid(int m, int n, int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }

    int dijstra(vector<vector<int>>& grid) {
        const int INF = 1e9;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> obstacleCount(m, vector<int>(n, INF));
        priority_queue<pair<int, pair<int, int>>,
            vector<pair<int, pair<int, int>>>, greater<>> minHeap;

        minHeap.push({0, {0, 0}});
        obstacleCount[0][0] = 0;

        vector<int> dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};
        while (!minHeap.empty()) {
            int obstacleRemoved = minHeap.top().first;
            int x = minHeap.top().second.first, y = minHeap.top().second.second;
            minHeap.pop();

            if (x == m - 1 && y == n - 1) return obstacleRemoved;

            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i], newY = y + dy[i];
                if (isValid(m, n, newX, newY) && 
                    obstacleRemoved + grid[newX][newY] < obstacleCount[newX][newY]) {
                        obstacleCount[newX][newY] = obstacleRemoved + grid[newX][newY];
                        minHeap.push({obstacleCount[newX][newY], {newX, newY}});
                    }
            }
        }

        return obstacleCount[m - 1][n - 1];
    }

public:
    int minimumObstacles(vector<vector<int>>& grid) {
        return dijstra(grid);
    }
};