class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), totalSum = 0;

        for (int i = 0; i < n; i++) totalSum += nums[i];
        if (totalSum & 1) return false;

        vector<vector<int>> dp(n, vector<int>(totalSum / 2 + 1, -1));
        
        for (int idx = 0; idx < n; idx++) {
            for (int target = 0; target <= totalSum / 2; target++) {
                if (target == 0) dp[idx][target] = 0;
                else if (idx == 0) dp[idx][target] = nums[idx] == target;
                else {
                    bool exclude = dp[idx - 1][target], include = false;
                    if (!exclude && nums[idx] <= target) 
                        include = dp[idx - 1][target - nums[idx]];
                    dp[idx][target] = include || exclude;
                }
            }
        }

        return dp[n - 1][totalSum / 2];
    }
};