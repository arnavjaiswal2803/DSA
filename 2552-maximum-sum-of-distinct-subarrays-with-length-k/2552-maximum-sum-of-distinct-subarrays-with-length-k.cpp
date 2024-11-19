class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int i = 0, n = nums.size();
        unordered_map<int, int> freq;
        long long maxSum = 0, sum = 0;

        while (i < k) {
            freq[nums[i]]++;
            sum += nums[i];
            i++;
        }
        if (freq.size() == k) maxSum = max(maxSum, sum);

        while (i < n) {
            freq[nums[i - k]]--;
            if (freq[nums[i - k]] == 0) freq.erase(nums[i - k]);

            freq[nums[i]]++;
            sum += nums[i] - nums[i - k];

            if (freq.size() == k) maxSum = max(maxSum, sum);

            i++;
        }

        return maxSum;
    }
};