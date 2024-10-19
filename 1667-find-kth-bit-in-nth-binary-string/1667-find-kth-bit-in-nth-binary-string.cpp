class Solution {
    string reverseString(string str) {
        reverse(str.begin(), str.end());
        return str;
    }

    string invertString(string str) {
        string res = "";
        for (char ch : str) {
            if (ch == '0') res += '1';
            else res += '0';
        }
        return res;
    }

    string generateNthBinaryString(int n) {
        if (n == 1) return "0";

        string prevStr = generateNthBinaryString(n - 1);
        return prevStr + "1" + reverseString(invertString(prevStr));
    }
public:
    char findKthBit(int n, int k) {
        return generateNthBinaryString(n)[k - 1];
    }
};