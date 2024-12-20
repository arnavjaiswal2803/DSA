class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), maxProfit = 0, minPrice = prices[0];
        for (int i = 1; i < n; i++) {
            if (prices[i] > minPrice) 
                maxProfit = max(maxProfit, prices[i] - minPrice);
            else minPrice = prices[i];
        }
        return maxProfit;
    }
};