class Solution {
    int maxProfit(vector<int>& prices, int n, int idx, bool buy, int txnCnt, 
        vector<vector<vector<int>>>& dp) {
            if (idx == n || txnCnt == 2) return 0;
            if (dp[idx][buy][txnCnt] != -1) return dp[idx][buy][txnCnt];

            int profit = 0;
            if (buy) {
                profit = max(maxProfit(prices, n, idx + 1, buy, txnCnt, dp), 
                    -prices[idx] + maxProfit(prices, n, idx + 1, !buy, txnCnt, dp));
            } else {
                profit = max(maxProfit(prices, n, idx + 1, buy, txnCnt, dp), 
                    prices[idx] + maxProfit(prices, n, idx + 1, !buy, txnCnt+1, dp));
            }

            return dp[idx][buy][txnCnt] = profit;
        }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
        return maxProfit(prices, n, 0, true, 0, dp);
    }
};