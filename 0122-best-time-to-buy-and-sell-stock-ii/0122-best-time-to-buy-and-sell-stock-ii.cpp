class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2);

        ahead[0] = ahead[1] = 0;
        for (int idx = n - 1; idx >= 0; --idx) {
            vector<int> curr(2);
            for (int buy = 0; buy <= 1; ++buy) {
                int profit = 0;
                if (buy) {
                    profit = max(-prices[idx] + ahead[!buy], ahead[buy]);
                } else {
                    profit = max(prices[idx] + ahead[!buy], ahead[buy]);
                }
                curr[buy] = profit;
            }
            ahead = curr;
        }

        return ahead[true];
    }
};