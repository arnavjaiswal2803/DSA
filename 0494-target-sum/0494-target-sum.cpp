class Solution {
    int ways(vector<int>& nums, int target, int idx, 
        map<pair<int, int>, int>& dp) {
            if (idx == 0) {
                if (target + nums[idx] == 0 && target - nums[idx] == 0) return 2;
                if (target + nums[idx] == 0 || target - nums[idx] == 0) return 1;
                return 0;
            };
            if (dp.find({idx, target}) != dp.end()) return dp[{idx, target}];

            int add = ways(nums, target - nums[idx], idx - 1, dp);
            int sub = ways(nums, target + nums[idx], idx - 1, dp);
            return dp[{idx, target}] = add + sub;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        map<pair<int, int>, int> dp;
        return ways(nums, target, n - 1, dp);
    }
};