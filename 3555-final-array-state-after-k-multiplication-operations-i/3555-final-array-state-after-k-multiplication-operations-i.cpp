class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        vector<int> ans(nums);
        while (k--) {
            int minIdx = 0;
            for (int i = 1; i < n; i++) if (ans[i] < ans[minIdx]) minIdx = i;
            ans[minIdx] *= multiplier;
        }
        return ans;
    }
};