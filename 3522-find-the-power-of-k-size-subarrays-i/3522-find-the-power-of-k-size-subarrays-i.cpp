class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
         if (k == 1) {
            return nums;
        }

        int n = nums.size(), counter = 1;
        vector<int> ans(n - k + 1);

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) counter++;
            else counter = 1;

            if (i >= k - 1) ans[i - k + 1] = counter >= k ? nums[i] : -1;
        }

        return ans;
    }
};