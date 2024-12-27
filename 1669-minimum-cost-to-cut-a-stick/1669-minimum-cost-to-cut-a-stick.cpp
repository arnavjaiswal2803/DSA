class Solution {
    int minCost(vector<int>& cuts, int i, int j, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] !=  -1) return dp[i][j];

        int minn = 1e9;
        for (int k = i; k <= j; k++) {
            int cost =  cuts[j + 1] - cuts[i - 1] + minCost(cuts, i, k - 1, dp) +
                minCost(cuts, k + 1, j, dp);
            minn = min(minn, cost);
        }
        return dp[i][j] = minn;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        int cutsSize = cuts.size();
        vector<vector<int>> dp(cutsSize, vector<int>(cutsSize, -1));

        return minCost(cuts, 1, cutsSize - 2, dp);
    }
};