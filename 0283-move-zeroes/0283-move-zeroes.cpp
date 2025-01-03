class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        while (i < n && nums[i] != 0) i++;
        int j = i;
        while (i < n && j < n) {
            while (j < n && nums[j] != 0) j++;
            if (j < n) swap(nums[j], nums[i]);
            i++;
        }
    }
};