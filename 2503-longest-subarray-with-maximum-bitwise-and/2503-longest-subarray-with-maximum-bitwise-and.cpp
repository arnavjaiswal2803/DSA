class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxNum = nums[0], startIdx = 0, endIdx = 0, maxLen = 1, n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] >= maxNum) {
                if (nums[i] > maxNum) {
                    maxNum = nums[i];
                    startIdx = i;
                    endIdx = i;
                    maxLen = 1;
                } else {
                    if (nums[i] != nums[i - 1]) startIdx = i;
                    endIdx = i;
                    
                    int len = endIdx - startIdx + 1;
                    maxLen = max(maxLen, len);
                }
            }
        }
        return maxLen;
    }
};