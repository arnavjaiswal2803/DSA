class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        int cutsSize = cuts.size();
        vector<vector<int>> dp(cutsSize, vector<int>(cutsSize, 0));

        for (int i = cutsSize - 2; i >= 1; --i) {
            for (int j = i; j <= cutsSize - 2; j++) {
                int minn = 1e9;
                for (int k = i; k <= j; k++) {
                    int cost =
                        cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                    minn = min(minn, cost);
                }
                dp[i][j] = minn;
            }
        }

        return dp[1][cutsSize - 2];
    }
};