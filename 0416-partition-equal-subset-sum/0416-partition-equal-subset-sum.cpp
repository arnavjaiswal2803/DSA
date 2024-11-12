class Solution {
    bool canPartition(vector<int> &nums, int idx, int sum1, int sum2, 
        vector<vector<int>> &dp) {
            if (sum1 == sum2 && sum1 != 0) return true;
            if (idx < 0) return false;
            if (dp[idx][sum1] != -1) return dp[idx][sum1];

            return dp[idx][sum1] = canPartition(nums, idx - 1, sum1, sum2, dp) || 
                canPartition(nums, idx - 1, sum1 + nums[idx], sum2 - nums[idx], dp);
        }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; i++) sum += nums[i];
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return canPartition(nums, n - 1, 0, sum, dp);
    }
};