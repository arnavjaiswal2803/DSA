class Solution {
    int countSubarraysWithSumLessThanOrEqualToK(vector<int> &nums, int k) {
        if (k < 0) return 0;

        int start = 0, end = 0, sum = 0, count = 0, n = nums.size();
        while (end < n) {
            if (sum + nums[end] <= k) {
                sum += nums[end];
                count += end - start + 1;
                end++;
            } else {
                sum -= nums[start];
                start++;
            }
        }
        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countSubarraysWithSumLessThanOrEqualToK(nums, goal) - 
            countSubarraysWithSumLessThanOrEqualToK(nums, goal - 1);
    }
};