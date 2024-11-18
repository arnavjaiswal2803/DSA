class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int n = nums.size(), len = 0, minLen = INT_MAX;
        long long sum = 0;
        vector<long long> prefixSum(n);

        for (int i = 0; i < n; i++) {
            prefixSum[i] = (long long)nums[i];
            if (i > 0) prefixSum[i] += prefixSum[i - 1];
        }

        int left = 0;
        for (int right = 0; right < n; right++) {
            while (prefixSum[right] - prefixSum[left] >= (long long)k) {
                left++; 
            }
            if (prefixSum[right] >= k) minLen = min(minLen, right - left + 1);
        }

        return minLen != INT_MAX ? minLen : 0;
    }
};