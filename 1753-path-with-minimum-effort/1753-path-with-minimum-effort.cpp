class Solution {
    bool isValid(int m, int n, int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int INF = 1e9;
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> efforts(m, vector<int>(n, INF));
        queue<pair<int, int>> q;

        q.push({0, 0});
        efforts[0][0] = 0;

        vector<int> dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i], newY = y + dy[i];

                if (isValid(m, n, newX, newY)) {
                    int currEffort = max(efforts[x][y], 
                        abs(heights[newX][newY] - heights[x][y]));

                    if (currEffort < efforts[newX][newY]) {
                        efforts[newX][newY] = currEffort;
                        q.push({newX, newY});
                    }
                }
            }
        }

        return efforts[m - 1][n - 1];
    }
};