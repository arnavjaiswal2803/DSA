class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maxProfit = 0;
        vector<int> dp(n);

        for (int idx = n - 1; idx >= 0; --idx) {
            if (idx == n - 1) {
                dp[idx] = 0;
            } else {
                int profit = 0;
                for (int i = idx + 1; i < n; i++) {
                    int cost = prices[i]-prices[idx] > 0 ? prices[i]-prices[idx] : 0;
                    profit = max(profit, cost + dp[i]);
                }
                dp[idx] = profit;
            }
            maxProfit = max(maxProfit, dp[idx]);
        }

        return maxProfit;
    }
};