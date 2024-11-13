class Solution {
    int getIdxOfFirstElemLessThanTarget(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);

            if (nums[mid] >= target) high = mid - 1;
            else low = mid + 1;
        }
        return high;
    }

    int getIdxOfFirstElemGreaterThanTarget(vector<int> &nums, int target) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);

            if (nums[mid] <= target) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long count = 0;

        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++) {
            int floor = getIdxOfFirstElemLessThanTarget(nums, lower - nums[i]);
            int ceil = getIdxOfFirstElemGreaterThanTarget(nums, upper - nums[i]);

            int lessCount = floor + 1, greaterCount = n - ceil;
            count += (n - lessCount - greaterCount);

            if (i > floor && i  < ceil) count--;
        }

        return count / 2;
    }
};