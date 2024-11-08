class Solution {
    bool getBit(int num, int pos) { return (num & (1 << pos)) > 0; }
    int clearBit(int num, int pos) { return (num & (~(1 << pos))); }
    int setBit(int num, int pos) { return (num | (1 << pos)); }
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xorr = 0, maxK = pow(2, maximumBit) - 1, n = nums.size();
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            xorr ^= nums[i];
            int k = maxK;

            for (int pos = maximumBit - 1; pos >= 0; pos--) 
                k = getBit(xorr, pos) ? clearBit(k, pos) : k = setBit(k, pos);

            ans[n - 1 - i] = k;
        }

        return ans;
    }
};