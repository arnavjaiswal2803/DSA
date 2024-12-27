class Solution {
    int minCost(vector<int>& cuts, int cutsSize, int i, int j,
                map<pair<int, int>, int>& dp) {
        if (dp.find({i, j}) !=  dp.end()) return dp[{i, j}];

        int minn = 1e9;
        for (int k = 0; k < cutsSize; k++) {
            if (cuts[k] <= i || cuts[k] >= j) continue;
            int cost =  j - i + minCost(cuts, cutsSize, i, cuts[k], dp) +
                                 minCost(cuts, cutsSize, cuts[k], j, dp);
            minn = min(minn, cost);
        }
        return dp[{i, j}] = minn != 1e9 ? minn : 0;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        map<pair<int, int>, int> dp;
        return minCost(cuts, cuts.size(), 0, n, dp);
    }
};