class Solution {
public:
    char findKthBit(int n, int k) {
        bool isInvert = false;
        int currLen = (1 << n) - 1;

        while (k > 1) {
            if (k == (currLen / 2) + 1) return isInvert ? '0' : '1';
            if (k > currLen / 2) {
                k = currLen - k + 1;
                isInvert = !isInvert; 
            }
            currLen /= 2;
        }

        return isInvert ? '1' : '0';
    }
};