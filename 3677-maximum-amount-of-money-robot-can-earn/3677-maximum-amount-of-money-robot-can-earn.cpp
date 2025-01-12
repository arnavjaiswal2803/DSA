class Solution {
    int getMaxProfit(vector<vector<int>>& coins, int row, int col,
                     int neutralize, vector<vector<vector<int>>>& dp) {
        if (row < 0 || col < 0)
            return -1e9;
        if (row == 0 && col == 0) {
            return coins[row][col] >= 0 || neutralize == 0 ? coins[row][col]
                                                           : 0;
        }
        if (dp[row][col][neutralize] != -1e9+7) return dp[row][col][neutralize];

        if (coins[row][col] >= 0 || neutralize == 0) {
            return dp[row][col][neutralize] = coins[row][col] +
                   max(getMaxProfit(coins, row - 1, col, neutralize, dp),
                       getMaxProfit(coins, row, col - 1, neutralize, dp));
        }
        return dp[row][col][neutralize] = max(coins[row][col] +
                       max(getMaxProfit(coins, row - 1, col, neutralize, dp),
                           getMaxProfit(coins, row, col - 1, neutralize, dp)),
                   max(getMaxProfit(coins, row - 1, col, neutralize - 1, dp),
                       getMaxProfit(coins, row, col - 1, neutralize - 1, dp)));
    }

public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<vector<int>>> 
            dp(m, vector<vector<int>>(n, vector<int>(3, -1e9+7)));
        return getMaxProfit(coins, m - 1, n - 1, 2, dp);
    }
};