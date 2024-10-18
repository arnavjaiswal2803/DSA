class Solution {
    int count(vector<int> &nums, int idx, int currOr, int maxOr, 
        vector<vector<int>> &dp) {
            if (idx < 0) return currOr == maxOr ? 1 : 0;
            if (dp[idx][currOr] != -1) return dp[idx][currOr];

            return dp[idx][currOr] = count(nums, idx - 1, currOr, maxOr, dp) + 
                count(nums, idx - 1, currOr | nums[idx], maxOr, dp);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size(), maxOr = 0;
        for (int i = 0; i < n; i++) maxOr |= nums[i];
        vector<vector<int>> dp(n, vector<int>(maxOr + 1, -1));
        return count(nums, n - 1, 0, maxOr, dp);
    }
};