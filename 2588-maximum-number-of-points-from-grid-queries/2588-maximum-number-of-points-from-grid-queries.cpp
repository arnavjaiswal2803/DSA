class Solution {
    typedef pair<int, int> pii;

public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size(), k = queries.size();

        vector<pair<int, int>> queryIdx(k);
        for (int i = 0; i < k; i++)
            queryIdx[i] = {queries[i], i};
        sort(queryIdx.begin(), queryIdx.end());

        int points = 0, idx = 0;
        vector<int> ans(k);
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>>
            minHeap;

        minHeap.push({grid[0][0], {0, 0}});
        vis[0][0] = true;

        while (!minHeap.empty()) {
            int elem = minHeap.top().first;
            int row = minHeap.top().second.first;
            int col = minHeap.top().second.second;
            minHeap.pop();

            while (idx < k && queryIdx[idx].first <= elem) {
                ans[queryIdx[idx].second] = points;
                idx++;
            }
            if (idx == k)
                return ans;

            points++;

            vector<int> dRow = {0, 1, 0, -1}, dCol = {-1, 0, 1, 0};
            for (int i = 0; i < 4; i++) {
                int newRow = row + dRow[i], newCol = col + dCol[i];
                if (isValid(m, n, newRow, newCol, vis)) {
                    minHeap.push({grid[newRow][newCol], {newRow, newCol}});
                    vis[newRow][newCol] = true;
                }
            }
        }

        for (idx; idx < k; idx++)
            ans[queryIdx[idx].second] = points;

        return ans;
    }

private:
    bool isValid(int m, int n, int newRow, int newCol,
                 vector<vector<bool>>& vis) {
        return newRow >= 0 && newRow < m && newCol >= 0 && newCol < n &&
               !vis[newRow][newCol];
    }
};