class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> finalPrices(prices);

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (prices[j] <= prices[i]) {
                    finalPrices[i] -= prices[j];
                    break;
                }
            }
        }
        
        return finalPrices;
    }
};