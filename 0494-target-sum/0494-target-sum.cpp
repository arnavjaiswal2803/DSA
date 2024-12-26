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
        vector<int> prev(2 * totalSum + 1, 0);

        prev[nums[0] + totalSum] = 1;
        prev[-nums[0] + totalSum] += 1;

        for (int idx = 1; idx < n; idx++) {
            vector<int> curr(2 * totalSum + 1, 0);
            for (int currSum = -totalSum; currSum <= totalSum; currSum++) {
                if (prev[currSum + totalSum] > 0) {
                    curr[currSum + nums[idx] + totalSum] +=
                        prev[currSum + totalSum];
                    curr[currSum - nums[idx] + totalSum] +=
                        prev[currSum + totalSum];
                }
            }
            prev = curr;
        }

        return abs(target) > totalSum ? 0 : prev[target + totalSum];
    }
};