class Solution {
    bool isUniversal(string& s1, unordered_map<char, int> freq) {
        for (char &ch : s1) {
            if (freq.find(ch) != freq.end()) {
                freq[ch]--;
                if (freq[ch] == 0) freq.erase(ch); 
            }
        }
        return freq.size() == 0;
    }
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size(), m = words2.size();
        unordered_map<char, int> freq;
        vector<string> universalStrings;

        for (char &ch : words2[0]) freq[ch]++;

        for (int i = 1; i < m; i++) {
            unordered_map<char, int> currFreq;
            for (char &ch : words2[i]) {
                currFreq[ch]++;
                if (currFreq[ch] > freq[ch]) freq[ch]++;
            }
        }
        
        for (string& s1 : words1) 
            if (isUniversal(s1, freq)) universalStrings.push_back(s1);

        return universalStrings;
    }
};