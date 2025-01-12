class Solution {
    public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<vector<int>>> dp(
            m + 1, vector<vector<int>>(n + 1, vector<int>(3, -1e9 + 7)));

        for (int row = 1; row <= m; row++) {
            for (int col = 1; col <= n; col++) {
                for (int neutralize = 0; neutralize <= 2; neutralize++) {

                    if (row == 1 && col == 1) {
                        dp[row][col][neutralize] =
                            coins[row - 1][col - 1] >= 0 || neutralize == 0
                                ? coins[row - 1][col - 1]
                                : 0;
                    } else {
                        if (coins[row - 1][col - 1] >= 0 || neutralize == 0) {
                            dp[row][col][neutralize] =
                                coins[row - 1][col - 1] +
                                max(dp[row - 1][col][neutralize],
                                    dp[row][col - 1][neutralize]);
                        } else {
                            dp[row][col][neutralize] =
                                max(coins[row - 1][col - 1] +
                                        max(dp[row - 1][col][neutralize],
                                            dp[row][col - 1][neutralize]),
                                    max(dp[row - 1][col][neutralize - 1],
                                        dp[row][col - 1][neutralize - 1]));
                        }
                    }
                }
            }
        }

        return dp[m][n][2];
    }
};