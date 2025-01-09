class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n - 1;
        for (i = n - 1; i > 0; --i) {
            if (nums[i - 1] < nums[i]) {
                int j = n - 1;
                while (j > i - 1 && nums[j] <= nums[i - 1]) j--;
                swap(nums[j], nums[i - 1]);
                break;
            }
        }
        sort(nums.begin() + i, nums.end());
    }
};