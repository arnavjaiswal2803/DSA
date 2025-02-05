class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        vector<int> freq(26, 0);

        for (char &ch : s1) freq[ch - 'a']++;
        for (char &ch : s2) freq[ch - 'a']--;
        for (int i = 0; i < 26; i++) if (freq[i] != 0) return false;

        int diffCharCount = 0;
        for (int i = 0; i < n; i++) if (s1[i] != s2[i]) diffCharCount++;

        return diffCharCount <= 2;
    }
};