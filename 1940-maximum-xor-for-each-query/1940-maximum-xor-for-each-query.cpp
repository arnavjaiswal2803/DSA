class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xorr = 0, maxK = pow(2, maximumBit) - 1, n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            xorr ^= nums[i];
            ans[n - 1 - i] = maxK ^ xorr;
        }

        return ans;
    }
};