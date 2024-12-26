class Solution {
    int ways(vector<int>& nums, int idx, int currSum, int target, int totalSum,
             vector<vector<int>>& dp) {
        if (idx == 0) {
            if (currSum + nums[idx] == target && currSum - nums[idx] == target)
                return 2;
            if (currSum + nums[idx] == target || currSum - nums[idx] == target)
                return 1;
            return 0;
        }
        if (dp[idx][currSum + totalSum] != INT_MIN)
            return dp[idx][currSum + totalSum];

        int add =
            ways(nums, idx - 1, currSum + nums[idx], target, totalSum, dp);
        int sub =
            ways(nums, idx - 1, currSum - nums[idx], target, totalSum, dp);
        return dp[idx][currSum + totalSum] = add + sub;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(n, vector<int>(2 * totalSum + 1, 0));

        dp[0][nums[0] + totalSum] = 1;
        dp[0][-nums[0] + totalSum] += 1;

        for (int idx = 1; idx < n; idx++) {
            for (int currSum = -totalSum; currSum <= totalSum; currSum++) {
                if (dp[idx - 1][currSum + totalSum] > 0) {
                    dp[idx][currSum + nums[idx] + totalSum] +=
                        dp[idx - 1][currSum + totalSum];
                    dp[idx][currSum - nums[idx] + totalSum] +=
                        dp[idx - 1][currSum + totalSum];
                }
            }
        }

        return abs(target) > totalSum ? 0 : dp[n - 1][target + totalSum];
    }
};