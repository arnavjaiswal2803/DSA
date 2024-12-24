class Solution {
    int maxProfit(vector<int>& prices, int n,  int idx, bool buy, 
        vector<vector<int>>& dp) {
            if (idx == n) return 0;
            if (dp[idx][buy] != -1) return dp[idx][buy];

            int profit = 0;
            if (buy) {
                profit = max(-prices[idx] + maxProfit(prices, n, idx + 1, !buy, dp), 
                    0 + maxProfit(prices, n, idx + 1, buy, dp));
            } else {
                profit = max(prices[idx] + maxProfit(prices, n, idx + 1, !buy, dp), 
                    maxProfit(prices, n, idx + 1, buy, dp));
            }
            return dp[idx][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return maxProfit(prices, n, 0, true, dp);
    }
};