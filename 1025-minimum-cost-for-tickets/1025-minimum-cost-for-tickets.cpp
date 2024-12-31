class Solution {
    int minCost(vector<int>& days, vector<int>& costs, int n, int idx, 
        int validUpto, vector<vector<int>>& dp) {
            if (idx == n) return 0;
            if (dp[idx][validUpto] != -1) return dp[idx][validUpto];

            if (days[idx] <= validUpto) 
                return minCost(days, costs, n, idx + 1, validUpto, dp);
            return dp[idx][validUpto] = min({
                costs[0] + minCost(days, costs, n, idx + 1, days[idx], dp), 
                costs[1] + minCost(days, costs, n, idx + 1, days[idx] + 6, dp), 
                costs[2] + minCost(days, costs, n, idx + 1, days[idx] + 29, dp)
            });
        }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<vector<int>> dp(n + 1, vector<int>(days[n - 1] + 30, -1));
        return minCost(days, costs, n, 0, 0, dp);
    }
}; 