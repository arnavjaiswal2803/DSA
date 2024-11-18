class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0, minLen = INT_MAX;
        long long sum = 0;

        while (right < n) {
            sum += (long long)nums[right];
            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }

        return minLen != INT_MAX ? minLen : 0;
    }
};