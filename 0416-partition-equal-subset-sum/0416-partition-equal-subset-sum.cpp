class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), totalSum = 0;

        for (int i = 0; i < n; i++) totalSum += nums[i];
        if (totalSum & 1) return false;

        vector<int> prev(totalSum / 2 + 1);
        
        for (int idx = 0; idx < n; idx++) {
            vector<int> curr(totalSum / 2 + 1);
            for (int target = 0; target <= totalSum / 2; target++) {
                if (target == 0) curr[target] = true;
                else if (idx == 0) curr[target] = nums[idx] == target;
                else {
                    bool exclude = prev[target], include = false;
                    if (!exclude && nums[idx] <= target) 
                        include = prev[target - nums[idx]];
                    curr[target] = include || exclude;
                }
            }
            prev = curr;
        }
        
        return prev[totalSum / 2];
    }
};