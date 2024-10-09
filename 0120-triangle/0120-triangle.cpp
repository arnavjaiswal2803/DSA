class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int row = n - 1; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                dp[row][col] = triangle[row][col];
                if (row < n - 1) 
                    dp[row][col] += min(dp[row + 1][col], dp[row + 1][col + 1]);
            }
        }

        return dp[0][0];
    }
};