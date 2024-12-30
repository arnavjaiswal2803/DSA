class Solution {
    const int MOD = 1e9 + 7;

    int count(int low, int high, int zero, int one, int len, vector<int>& dp) {
        if (dp[len] != -1) return dp[len];
        
        int cnt = len >= low ? 1 : 0;
        if (len + zero <= high) 
            cnt = (cnt + 
                (count(low, high, zero, one, len + zero, dp) % MOD)
            ) % MOD;
        if (len + one <= high) 
            cnt = (cnt + 
                (count(low, high, zero, one, len + one, dp) % MOD)
            ) % MOD;
        return dp[len] = cnt;
    }

public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, -1);
        return count(low, high, zero, one, 0, dp);
    }
};