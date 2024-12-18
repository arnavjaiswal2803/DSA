class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> nextSmaller;
        vector<int> ans(prices);

        nextSmaller.push(prices[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            while (!nextSmaller.empty() && prices[i] < nextSmaller.top()) 
                nextSmaller.pop();

            if (!nextSmaller.empty()) ans[i] -= nextSmaller.top();
            nextSmaller.push(prices[i]);
        }

        return ans;
    }
};