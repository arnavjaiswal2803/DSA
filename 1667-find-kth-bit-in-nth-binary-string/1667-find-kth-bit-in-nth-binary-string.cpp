class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0';

        int prevLen = pow(2, n - 1) - 1;
        if (k == prevLen + 1) return '1';
        else if (k <= prevLen) return findKthBit(n - 1, k);
        else return findKthBit(n - 1, 2 * prevLen - k + 2) == '0' ? '1' : '0';
    }
};