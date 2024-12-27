class Solution {
    int maxCoins(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int maxi = -1e7;
        for (int k = i; k <= j; k++) {
            int coins = nums[i - 1] * nums[k] * nums[j + 1] + 
                maxCoins(nums, i, k - 1, dp) + maxCoins(nums, k + 1, j, dp);
            maxi = max(maxi, coins);
        }

        return dp[i][j] = maxi;
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return maxCoins(nums, 1, n - 2, dp);
    }
};