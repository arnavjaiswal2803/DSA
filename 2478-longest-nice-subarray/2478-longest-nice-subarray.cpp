class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size(), maxLen = 1, start = 0, end = 0;
        bitset<32> hash;

        while (end < n) {
            for (int posEnd = 0; posEnd < 32; posEnd++) {
                if (getBit(nums[end], posEnd)) {
                    while (hash[posEnd]) {
                        for (int posStart = 0; posStart < 32; posStart++) {
                            if (getBit(nums[start], posStart)) 
                                hash[posStart] = 0;
                        }
                        
                        start++;
                    }

                    hash[posEnd] = 1;
                }
            }
            maxLen = max(maxLen, end - start + 1);

            end++;
        }

        return maxLen;
    }

private:
    bool getBit(int num, int pos) {
        return ((num >> pos) & 1) > 0;
    }
};