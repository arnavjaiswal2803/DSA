class Solution {
    bool subsetSum(vector<int> &nums, int idx, int target, vector<vector<int>> &dp) {
        if (target == 0) return true;
        if (idx == 0) return nums[idx] == target;
        if (dp[idx][target] != -1) return dp[idx][target];

        bool exclude = subsetSum(nums, idx - 1, target, dp), include = false;
        if (!exclude && nums[idx] <= target) 
            include = subsetSum(nums, idx - 1, target - nums[idx], dp);

        return dp[idx][target] = include || exclude;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), totalSum = 0;

        for (int i = 0; i < n; i++) totalSum += nums[i];
        if (totalSum & 1) return false;

        vector<vector<int>> dp(n, vector<int>(totalSum / 2 + 1, -1));
        return subsetSum(nums, n - 1, totalSum / 2, dp);
    }
};