class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size(), maxLen = 1, currIncLen = 1, currDecLen = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) currIncLen++;
            else currIncLen = 1;

            if (nums[i] < nums[i - 1]) currDecLen++;
            else currDecLen = 1;

            maxLen = max({maxLen, currIncLen, currDecLen});
        }

        return maxLen;
    }
};