class Solution {
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<bool> prev (target + 1, false);
        
        for (int idx = 0; idx < n; idx++) {
            vector<bool> curr (target + 1, false);
            for (int tar = 0; tar <= target; tar++) {
                if (tar == 0) curr[tar] = true;
                else if (idx == 0) curr[tar] = arr[idx] == tar;
                else {
                    bool pick = false, notPick = prev[tar];
                    if (!notPick && arr[idx] <= tar) 
                        pick = prev[tar - arr[idx]];
                    curr[tar] = (pick || notPick);
                }
            }
            prev = curr;
        }
        
        return prev[target];
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; i++) sum += nums[i];
        if (sum & 1) return false;
        return isSubsetSum(nums, sum / 2);
    }
};