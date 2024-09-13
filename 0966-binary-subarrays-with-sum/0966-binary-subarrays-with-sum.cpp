class Solution {
    int countSubarraysWithSumLessThanOrEqualToK(vector<int> &nums, int k) {
        if (k < 0) return 0;

        int start = 0, end = 0, sum = 0, count = 0, n = nums.size();
        while (end < n) {
            sum += nums[end];
            while (sum > k) {
                sum -= nums[start];
                start++;
            }
            count += end - start + 1;
            end++;
        }
        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return countSubarraysWithSumLessThanOrEqualToK(nums, goal) - 
            countSubarraysWithSumLessThanOrEqualToK(nums, goal - 1);
    }
};