class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size(), maxValidity = days[n - 1] + 30;
        vector<vector<int>> dp(n + 1, vector<int>(maxValidity + 1, 0));

        for (int idx = n - 1; idx >= 0; --idx) {
            for (int validUpto = maxValidity; validUpto >= 0; --validUpto) {
                if (days[idx] <= validUpto) 
                    dp[idx][validUpto] = dp[idx + 1][validUpto];
                else {
                    dp[idx][validUpto] = min({
                        costs[0] + dp[idx + 1][days[idx]], 
                        costs[1] + dp[idx + 1][days[idx] + 6], 
                        costs[2] + dp[idx + 1][days[idx] + 29]
                    });
                }
            }
        }

        return dp[0][0];
    }
}; 