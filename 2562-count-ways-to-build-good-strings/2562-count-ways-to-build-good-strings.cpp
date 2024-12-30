class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;
        vector<int> dp(high + 1, 0);

        for (int len = high; len >= 0; len--) {
            int cnt = len >= low ? 1 : 0;
            if (len + zero <= high) cnt = (cnt + dp[len + zero]) % MOD;
            if (len + one <= high) cnt = (cnt + dp[len + one]) % MOD;
            dp[len] = cnt;
        }

        return dp[0];
    }
};