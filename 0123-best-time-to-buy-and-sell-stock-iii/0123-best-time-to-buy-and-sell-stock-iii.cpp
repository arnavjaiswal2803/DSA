class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(3));

        for (int idx = n; idx >= 0; --idx) {
            vector<vector<int>> curr(2, vector<int>(3));
            for (int buy = 0; buy <= 1; ++buy) {
                for (int txnCnt = 2; txnCnt >= 0; --txnCnt) {
                    if (idx == n || txnCnt == 2) curr[buy][txnCnt] = 0;
                    else {
                        int profit = 0;
                        if (buy) {
                            profit = max(ahead[buy][txnCnt],
                                -prices[idx] + ahead[!buy][txnCnt]);
                        } else {
                            profit = max(ahead[buy][txnCnt],
                                prices[idx] + ahead[!buy][txnCnt + 1]);
                        }
                        curr[buy][txnCnt] = profit;
                    }
                }
            }
            ahead = curr;
        }

        return ahead[true][0];
    }
};