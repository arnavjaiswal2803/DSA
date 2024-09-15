//  see editorial to understand the code
class Solution {
    int setBit(int num, int pos) {
        return num ^ (1 << pos);
    }

    int getVowelPosition(char ch) {
        switch (ch) {
            case 'a': 
                return 0;
            case 'e': 
                return 1;
            case 'i':
                return 2;
            case 'o': 
                return 3;
            case 'u': 
                return 4;
            default:
                return -1;
        }
    }

    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    int findTheLongestSubstring(string s) {
        int n = s.length(), prefixXor = 0, maxLen = 0;
        vector<int> hash(32, -1); // size=32 coz, 5 vowels. Hence, maxVal = 2^5=32

        for (int i = 0; i < n; i++) {
            if (isVowel(s[i])) prefixXor ^= setBit(0, getVowelPosition(s[i]));

            if (prefixXor == 0) maxLen = i + 1;
            else if (hash[prefixXor] != -1) maxLen = max(maxLen, i - hash[prefixXor]);
            else hash[prefixXor] = i;
        }

        return maxLen;
    }
};