class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size(), n = grid[0].size(), N = m * n;
        if (N == 1) return 0;
        vector<int> arr(N);
        
        int idx = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) arr[idx++] = grid[i][j];
        }

        sort (arr.begin(), arr.end());

        int mid = arr[N / 2], operations = 0;
        for (int i = 0; i < N; i++) {
            if (abs(mid - arr[i]) % x != 0) return -1;
            operations += abs(mid - arr[i]) / x;
        }

        return operations;
    }
};