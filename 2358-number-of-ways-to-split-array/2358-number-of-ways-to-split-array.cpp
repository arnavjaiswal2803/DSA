class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size(), validSplits = 0;
        long currSum = 0, totalSum = accumulate(nums.begin(), nums.end(), (long)0);

        for (int i = 0; i < n - 1; i++) {
            currSum += nums[i];
            if (2 * currSum >= totalSum) validSplits++;
        }

        return validSplits;
    }
};