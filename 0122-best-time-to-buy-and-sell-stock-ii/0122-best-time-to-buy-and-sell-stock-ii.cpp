class Solution {
    int maxProfit(vector<int>& prices, int n, int idx, vector<int>& dp) {
        if (dp[idx] != -1) return dp[idx];

        int profit = 0;
        for (int i = idx + 1; i < n; i++) {
            int cost = prices[i] - prices[idx] > 0 ? prices[i] - prices[idx] : 0;
            profit = max(profit, cost + maxProfit(prices, n, i, dp));
        }
        return dp[idx] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), profit = 0;
        vector<int> dp(n, -1);
        for (int i = 0; i < n - 1; i++) {
            profit = max(profit, maxProfit(prices, n, i, dp));
        }
        return profit;
    }
};