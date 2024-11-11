class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;
        n--;
        for (long long mask = 1; n > 0; mask <<= 1) {
            if ((x & mask) == 0) {
                ans |= ((n & 1) * mask);
                n >>= 1;
            }
        }
        return ans;
    }
};