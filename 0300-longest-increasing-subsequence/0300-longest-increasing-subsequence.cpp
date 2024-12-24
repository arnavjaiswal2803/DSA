class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), maxLen = 1;
        vector<int> dp(n, 1);
        
        for (int idx = 0; idx < n; idx++) {
            for (int prevIdx = 0; prevIdx < idx; prevIdx++) {
                if (nums[prevIdx] < nums[idx]) 
                    dp[idx] = max(dp[idx], 1 + dp[prevIdx]);
            }
            maxLen = max(maxLen, dp[idx]);
        }

        return maxLen;
    }
};