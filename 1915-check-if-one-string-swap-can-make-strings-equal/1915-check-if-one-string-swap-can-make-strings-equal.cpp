class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length(), diffCharCount = 0;
        vector<int> freq(26, 0);

        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) diffCharCount++;
            freq[s1[i] - 'a']++;
            freq[s2[i] - 'a']--;
        }
        if (diffCharCount > 2) return false;

        for (int i = 0; i < 26; i++) if (freq[i] != 0) return false;
        
        return true;
    }
};