class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size(), maxLen = 1;

        for (int i = 0; i < n; i++) {
            bool isIncreasing = true, isDecreasing = true;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] <= nums[j - 1]) isIncreasing = false;
                if (nums[j] >= nums[j - 1]) isDecreasing = false;

                if (isIncreasing || isDecreasing) maxLen = max(maxLen, j - i + 1);
                else break;
            }
        }

        return maxLen;
    }
};