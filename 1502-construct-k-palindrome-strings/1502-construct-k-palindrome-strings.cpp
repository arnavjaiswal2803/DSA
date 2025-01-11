class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size()) return false;

        int oddCount = 0;
        vector<int> freq(26, 0);

        for (char &ch : s) freq[ch - 'a']++;
        for (int i = 0; i < 26; i++) if (freq[i] & 1) oddCount++;
        
        return oddCount <= k;
    }
};