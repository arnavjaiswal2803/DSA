class Solution {
    const int MOD = 1e9 + 7;

    int count(int low, int high, int zero, int one, int len, vector<int>& dp) {
        if (len > high) return 0;
        if (dp[len] != -1) return dp[len];
        if (len >= low) {
            return dp[len] = (
                1 + 
                (count(low, high, zero, one, len + zero, dp) % MOD) +
                (count(low, high, zero, one, len + one, dp) % MOD)
            ) % MOD;
        }

        return dp[len] = (
                (count(low, high, zero, one, len + zero, dp) % MOD) +
                (count(low, high, zero, one, len + one, dp) % MOD)
            ) % MOD;
    }

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        return count(low, high, zero, one, 0, dp);
    }
};