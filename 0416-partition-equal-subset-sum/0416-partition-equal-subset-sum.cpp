class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum & 1) return false;
        int target = totalSum / 2;
        return isTargetPossible(nums, nums.size() - 1, target);
    }

private:
    bool isTargetPossible(vector<int>& nums, int idx, int target) {
        vector<bool> prev(target + 1, false);

        for (int i = 0; i <= idx; i++) {
            vector<bool> curr(target + 1, false);

            for (int t = 0; t <= target; t++) {
                if (i == 0) curr[t] = nums[i] == t;
                else if (t == 0) curr[t] = true;
                else {
                    bool notTake = prev[t], take = false;
                    if (nums[i] <= t) {
                        take = prev[t - nums[i]];
                    }
                    curr[t] = take || notTake;
                }
            }

            prev = curr;
        }

        return prev[target];
    }
};