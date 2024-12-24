class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1,
                                       vector<vector<int>>(2, vector<int>(3)));

        for (int idx = n; idx >= 0; --idx) {
            for (int buy = 0; buy <= 1; ++buy) {
                for (int txnCnt = 2; txnCnt >= 0; --txnCnt) {
                    if (idx == n || txnCnt == 2) dp[idx][buy][txnCnt] = 0;
                    else {
                        int profit = 0;
                        if (buy) {
                            profit = max(dp[idx + 1][buy][txnCnt],
                                -prices[idx] + dp[idx + 1][!buy][txnCnt]);
                        } else {
                            profit = max(dp[idx + 1][buy][txnCnt],
                                prices[idx] + dp[idx + 1][!buy][txnCnt + 1]);
                        }
                        dp[idx][buy][txnCnt] = profit;
                    }
                }
            }
        }

        return dp[0][true][0];
    }
};