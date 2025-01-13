class Solution {
public:
    int minimumLength(string s) {
        int minLen = 0;
        vector<int> freq(26, 0);

        for (char &ch : s) freq[ch - 'a']++;
        for (int i = 0; i < 26; i++) if (freq[i] > 0) minLen += freq[i] & 1 ? 1 : 2;

        return minLen;
    }
};