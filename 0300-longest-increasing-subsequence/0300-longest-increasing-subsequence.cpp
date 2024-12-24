class Solution {
    int lowerBound(vector<int>& nums, int val) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);

            if (nums[mid] >= val) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), len = 1;
        vector<int> temp;

        temp.push_back(nums[0]);
        for (int i = 1; i < n; i++) {
            if (nums[i] > temp.back()) {
                temp.push_back(nums[i]);
                len++;
            } else {
                int idx = lowerBound(temp, nums[i]);
                temp[idx] = nums[i];
            }
        }

        return len;
    }
};