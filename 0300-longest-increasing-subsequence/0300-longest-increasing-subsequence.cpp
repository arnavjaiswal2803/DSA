class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ahead(n + 1);

        for (int idx = n; idx >= 0; --idx) {
            vector<int> curr(n + 1);
            for (int prevIdx = idx - 1; prevIdx >= -1; --prevIdx) {
                if (idx == n) curr[prevIdx + 1] = 0;
                else {
                    int exclude = ahead[prevIdx + 1], include = 0;
                    if (prevIdx == -1 || nums[idx] > nums[prevIdx]) 
                        include = 1 + ahead[idx + 1];

                    curr[prevIdx + 1] = max(include, exclude);
                }
            }
            ahead = curr;
        }
        
        return ahead[0];
    }
};