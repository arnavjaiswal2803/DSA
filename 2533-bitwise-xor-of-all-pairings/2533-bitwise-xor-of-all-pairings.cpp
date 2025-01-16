class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), xorr = 0;
        if (n & 1) for (int &num : nums2) xorr ^= num;
        if (m & 1) for (int &num : nums1) xorr ^= num;
        return xorr;
    }
};