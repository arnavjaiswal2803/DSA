class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), ans = INT_MAX;
        vector<int> prev(n);

        for (int row = 0; row < n; row++) {
            vector<int> curr(n);
            for (int col = 0; col < n; col++) {
                if (row == 0) curr[col] = matrix[row][col];
                else {
                    int prevSum = prev[col];
                    if (col > 0) prevSum = min(prevSum, prev[col - 1]);
                    if (col < n - 1) prevSum = min(prevSum, prev[col + 1]);

                    curr[col] = matrix[row][col] + prevSum;
                }
                if (row == n - 1) ans = min(ans, curr[col]);
            }
            prev = curr;
        }

        return ans;
    }
};