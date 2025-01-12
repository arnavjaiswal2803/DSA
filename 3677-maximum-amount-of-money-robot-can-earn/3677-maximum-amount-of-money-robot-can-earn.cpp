class Solution {
    public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<int>> prev(n + 1, vector<int>(3, -1e9 + 7));

        for (int row = 1; row <= m; row++) {
            vector<vector<int>> curr(n + 1, vector<int>(3, -1e9 + 7));

            for (int col = 1; col <= n; col++) {
                for (int neutralize = 0; neutralize <= 2; neutralize++) {

                    if (row == 1 && col == 1) {
                        curr[col][neutralize] =
                            coins[row - 1][col - 1] >= 0 || neutralize == 0
                                ? coins[row - 1][col - 1]
                                : 0;
                    } else {
                        if (coins[row - 1][col - 1] >= 0 || neutralize == 0) {
                            curr[col][neutralize] =
                                coins[row - 1][col - 1] +
                                max(prev[col][neutralize],
                                    curr[col - 1][neutralize]);
                        } else {
                            curr[col][neutralize] =
                                max(coins[row - 1][col - 1] +
                                        max(prev[col][neutralize],
                                            curr[col - 1][neutralize]),
                                    max(prev[col][neutralize - 1],
                                        curr[col - 1][neutralize - 1]));
                        }
                    }

                }
            }

            prev = curr;
        }

        return prev[n][2];
    }
};