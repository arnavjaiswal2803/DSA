class Solution {
    bool getBit(int num, int pos) {
        return ((num >> pos) & 1) != 0;
    }

    void setBit(int& num, int pos) {
        num |= (1 << pos);
    }
public:
    int minimizeXor(int num1, int num2) {
        int num1SetBits = __builtin_popcount(num1);
        int num2SetBits = __builtin_popcount(num2);

        if (num1SetBits == num2SetBits) return num1;

        if (num1SetBits > num2SetBits) {
            int x = 0, setBitsInX = 0;
            for (int pos = 31; pos >= 0 && setBitsInX < num2SetBits; pos--) {
                if (getBit(num1, pos)) {
                    setBit(x, pos);
                    setBitsInX++;
                }
            }
            return x;
        }

        int x = num1, diff = num2SetBits - num1SetBits;
        for (int pos = 0; pos < 32 && diff > 0; pos++) {
            if (!getBit(num1, pos)) {
                setBit(x, pos);
                diff--;
            }
        }
        return x;
    }
};