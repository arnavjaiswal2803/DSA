class Solution {
    bool isValid(int m, int n, int x, int y) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int INF = 1e9;
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> efforts(m, vector<int>(n, INF));
        priority_queue<pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, greater<>> pq;

        pq.push({0, {0, 0}});
        efforts[0][0] = 0;

        vector<int> dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};
        while (!pq.empty()) {
            int diff = pq.top().first;
            int x = pq.top().second.first, y = pq.top().second.second;
            pq.pop();

            if (x == m - 1 && y == n - 1) return diff;

            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i], newY = y + dy[i];

                if (isValid(m, n, newX, newY)) {
                    int currEffort = max(diff, 
                        abs(heights[newX][newY] - heights[x][y]));

                    if (currEffort < efforts[newX][newY]) {
                        efforts[newX][newY] = currEffort;
                        pq.push({efforts[newX][newY], {newX, newY}});
                    }
                }
            }
        }

        return efforts[m - 1][n - 1];
    }
};