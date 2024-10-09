class Solution {
    int minSum(int row, int col, int maxRow, vector<vector<int>>& triangle, 
        vector<vector<int>>& dp) {
            if (row == maxRow) return triangle[row][col];
            if (dp[row][col] != -1) return dp[row][col];

            return dp[row][col] =  triangle[row][col] + 
                min(minSum(row + 1, col, maxRow, triangle, dp), 
                    minSum(row + 1, col + 1, maxRow, triangle, dp));
        }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return minSum(0, 0, n - 1, triangle, dp);
    }
};