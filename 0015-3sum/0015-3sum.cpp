class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> triplets;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1, k = n - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    triplets.push_back({nums[i], nums[j], nums[k]});

                    while (j + 1 < n && nums[j + 1] == nums[j]) j++;
                    j++;
                    while (k - 1 >= 0 && nums[k - 1] == nums[k]) k--;
                    k--;
                } else if (nums[i] + nums[j] + nums[k] < 0) j++;
                else k--;
            }
        }

        return triplets;
    }
};