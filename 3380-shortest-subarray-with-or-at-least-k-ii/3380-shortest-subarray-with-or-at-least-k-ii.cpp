class Solution {
    int getBit(int num, int pos) { return (((num >> pos) & 1) > 0); }
    int clearBit(int num, int pos) { return (num & (~(1 << pos))); }
    int setBit(int num, int pos) { return (num | (1 << pos)); }

    void incrementFreqAndUpdateMask(int num, int &mask, vector<int> &freq) {
        for (int i = 0; i < 32; i++) {
            if (getBit(num, i)) freq[i]++;
            if (freq[i] == 1) mask = setBit(mask, i);
        }
    }

    void decrementFreqAndUpdateMask(int num, int &mask, vector<int> &freq) {
        for (int i = 0; i < 32; i++) {
            if (getBit(num, i)) freq[i]--;
            if (freq[i] == 0) mask = clearBit(mask, i);
        }
    }
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> freq(32, 0);
        int n = nums.size(), mask = 0, start = 0, end = 0, minLen = n + 1;

        while (end < n) {
            if (nums[end] >= k) return 1;

            incrementFreqAndUpdateMask(nums[end], mask, freq);
            while (mask >= k && start <= end) {
                minLen = min(minLen, end - start + 1);
                decrementFreqAndUpdateMask(nums[start], mask, freq);
                start++;
            }
            end++;
        }

        return minLen <= n ? minLen : -1;
    }
};