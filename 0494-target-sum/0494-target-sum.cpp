class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> prev(2 * totalSum + 1, 0);

        prev[nums[0] + totalSum] = 1;
        prev[-nums[0] + totalSum] += 1;

        for (int idx = 1; idx < n; idx++) {
            vector<int> curr(2 * totalSum + 1, 0);
            for (int currSum = -totalSum; currSum <= totalSum; currSum++) {
                if (prev[currSum + totalSum] > 0) {
                    curr[currSum + nums[idx] + totalSum] +=
                        prev[currSum + totalSum];
                    curr[currSum - nums[idx] + totalSum] +=
                        prev[currSum + totalSum];
                }
            }
            prev = curr;
        }

        return abs(target) > totalSum ? 0 : prev[target + totalSum];
    }
};