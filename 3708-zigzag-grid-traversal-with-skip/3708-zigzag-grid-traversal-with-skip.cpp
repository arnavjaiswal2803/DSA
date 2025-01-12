class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans;
        bool reverse = false, skip = false;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int idx = reverse ? n - 1 - j : j;
                if (!skip) ans.push_back(grid[i][idx]);
                skip = !skip;
            }
            reverse = !reverse;
        }

        return ans;
    }
};