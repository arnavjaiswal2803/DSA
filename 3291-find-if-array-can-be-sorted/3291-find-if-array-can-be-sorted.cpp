class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] <= nums[i + 1]) continue;
            else if (__builtin_popcount(nums[i]) != __builtin_popcount(nums[i + 1]))
                return false;
            else swap(nums[i], nums[i + 1]);
        }

        for (int i = n - 1; i >= 1; i--) {
            if (nums[i] >= nums[i - 1]) continue;
            else if (__builtin_popcount(nums[i]) != __builtin_popcount(nums[i - 1]))
                return false;
            else swap(nums[i], nums[i - 1]);
        }

        return true;
    }
};