class Solution {
    bool isPossible(vector<int> &nums, int n, int windowSize, int target) {
        int right = 0;
        long long sum = 0;

        while (right < windowSize) sum += (long long)nums[right++];
        if (sum >= target) return true;

        while (right < n) {
            sum += (nums[right] - nums[right - windowSize]);
            if (sum >= target) return true;
            right++;
        }

        return false;
    }
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int low = 1, high = n;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);

            if (isPossible(nums, n, mid, target)) high = mid - 1;
            else low = mid + 1;
        }

        return low <= n ? low : 0;
    }
};