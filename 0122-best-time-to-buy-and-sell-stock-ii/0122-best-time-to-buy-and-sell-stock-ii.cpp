class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2));

        dp[n][0] = dp[n][1] = 0;
        for (int idx = n - 1; idx >= 0; --idx) {
            for (int buy = 0; buy <= 1; ++buy) {
                int profit = 0;
                if (buy) {
                    profit = max(-prices[idx] + dp[idx+1][!buy], dp[idx + 1][buy]);
                } else {
                    profit = max(prices[idx] + dp[idx+1][!buy], dp[idx + 1][buy]);
                }
                dp[idx][buy] = profit;
            }
        }

        return dp[0][true];
    }
};