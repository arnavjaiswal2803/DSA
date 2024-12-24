class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));

        for (int idx = n; idx >= 0; --idx) {
            for (int prevIdx = idx - 1; prevIdx >= -1; --prevIdx) {
                if (idx == n) dp[idx][prevIdx + 1] = 0;
                else {
                    int exclude = dp[idx + 1][prevIdx + 1], include = 0;
                    if (prevIdx == -1 || nums[idx] > nums[prevIdx]) 
                        include = 1 + dp[idx + 1][idx + 1];

                    dp[idx][prevIdx + 1] = max(include, exclude);
                }
            }
        }
        
        return dp[0][0];
    }
};