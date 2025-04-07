class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum & 1)
            return false;
        int target = totalSum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return isTargetPossible(nums, n - 1, target, dp);
    }

private:
    bool isTargetPossible(vector<int>& nums, int idx, int target,
                          vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (idx == 0) return nums[0] == target;

        if (dp[idx][target] != -1) return dp[idx][target];

        bool notTake = isTargetPossible(nums, idx - 1, target, dp), take = false;
        if (nums[idx] <= target) {
            take = isTargetPossible(nums, idx - 1, target - nums[idx], dp);
        }
        return dp[idx][target] = notTake || take;
    }
};