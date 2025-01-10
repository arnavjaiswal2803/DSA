class Solution {
    bool isUniversal(string& s1, vector<int> freq, int size) {
        for (char &ch : s1) {
            freq[ch - 'a']--;
            if (freq[ch - 'a'] == 0) size--; 
        }
        return size == 0;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size(), m = words2.size(), size = 0;
        vector<int> freq(26, 0);
        vector<string> universalStrings;

        for (char &ch : words2[0]) {
            freq[ch - 'a']++;
            if (freq[ch - 'a'] == 1) size++;
        }

        for (int i = 1; i < m; i++) {
            vector<int> currFreq(26, 0);
            for (char &ch : words2[i]) {
                currFreq[ch - 'a']++;
                if (currFreq[ch - 'a'] > freq[ch - 'a']) {
                    freq[ch - 'a']++;
                    if (freq[ch - 'a'] == 1) size++;
                }
            }
        }

        for (string& s1 : words1) 
            if (isUniversal(s1, freq, size)) universalStrings.push_back(s1);

        return universalStrings;
    }
};