class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum & 1) return false;
        int target = totalSum / 2;
        return isTargetPossible(nums, nums.size() - 1, target);
    }

private:
    bool isTargetPossible(vector<int>& nums, int idx, int target) {
        vector<vector<bool>> dp(nums.size(), vector<bool>(target + 1, false));

        for (int i = 0; i <= idx; i++) {
            for (int t = 0; t <= target; t++) {
                if (i == 0) dp[i][t] = nums[i] == t;
                else if (t == 0) dp[i][t] = true;
                else {
                    bool notTake = dp[i - 1][t], take = false;
                    if (nums[i] <= t) {
                        take = dp[i - 1][t - nums[i]];
                    }
                    dp[i][t] = take || notTake;
                }
            }
        }

        return dp[idx][target];
    }
};