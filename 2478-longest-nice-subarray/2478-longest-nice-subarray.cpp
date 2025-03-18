class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size(), maxLen = 1, bitmask = 0;

        for (int start = 0, end = 0; end < n; end++) {
            while ((bitmask & nums[end]) > 0) {
                bitmask ^= nums[start];
                start++;
            }
            bitmask |= nums[end];
            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};