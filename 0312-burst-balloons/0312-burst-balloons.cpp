class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 2; i >= 1; --i) {
            for (int j = i; j <= n - 2; ++j) {
                int maxi = -1e7;
                for (int k = i; k <= j; k++) {
                    int coins = nums[i - 1] * nums[k] * nums[j + 1] + 
                        dp[i][k - 1] + dp[k + 1][j];
                    maxi = max(maxi, coins);
                }
                dp[i][j] = maxi;
            }
        }

        return dp[1][n - 2];
    }
};