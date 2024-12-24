class Solution {
    int lis(vector<int>& nums, int n, int idx, int prevIdx, vector<vector<int>>& dp) {
        if (idx == n) return 0;
        if (dp[idx][prevIdx + 1] != -1) return dp[idx][prevIdx + 1];

        int len = lis(nums, n, idx + 1, prevIdx, dp);
        if (prevIdx == -1 || nums[idx] > nums[prevIdx]) 
            len = max(len, 1 + lis(nums, n, idx + 1, idx, dp));

        return dp[idx][prevIdx + 1] = len;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return lis(nums, n, 0, -1, dp);
    }
};