class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (m < n) return false;
        
        unordered_map<char, int> freq;
        for (auto ch : s1) freq[ch]++;

        for (int i = 0; i <= m - n; i++) {
            unordered_map<char, int> dupFreq = freq;
            int matchCount = 0;
            for (int j = i; j < m; j++) {
                char ch = s2[j];
                if (dupFreq.find(ch) != dupFreq.end() && dupFreq[ch] > 0) {
                    matchCount++;
                    dupFreq[ch]--;
                } else break;
            }
            if (matchCount == n) return true;
        }

        return false;
    }
}; 