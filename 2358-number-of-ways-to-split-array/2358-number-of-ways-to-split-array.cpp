class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size(), validSplits = 0;
        vector<long long> prefixSum(n);

        for (int i = 0; i < n; i++) {
            prefixSum[i] = nums[i];
            if (i > 0) prefixSum[i] += prefixSum[i - 1];
        }

        for (int i = 0; i < n - 1; i++) 
            if (prefixSum[i] >= prefixSum[n - 1] - prefixSum[i]) validSplits++;

        return validSplits;
    }
};