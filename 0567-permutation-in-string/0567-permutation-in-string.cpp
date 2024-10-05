class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (m < n) return false;

        vector<int> s1Freq(26, 0), s2Freq(26, 0);
        for (int i = 0; i < n; i++) {
            s1Freq[s1[i] - 'a']++;
            s2Freq[s2[i] - 'a']++;
        }

        int matchCount = 0;
        for (int i = 0; i < 26; i++) {
            if (s1Freq[i] == s2Freq[i]) matchCount++;
        }

        for (int i = 0; i < m - n; i++) {
            if (matchCount == 26) return true;

            int rightCh = s2[i + n], leftCh = s2[i];

            s2Freq[rightCh - 'a']++;
            if (s2Freq[rightCh - 'a'] == s1Freq[rightCh - 'a']) matchCount++;
            else if (s2Freq[rightCh - 'a'] - 1 == s1Freq[rightCh - 'a']) matchCount--;

            s2Freq[leftCh - 'a']--;
            if (s2Freq[leftCh - 'a'] == s1Freq[leftCh - 'a']) matchCount++;
            else if (s2Freq[leftCh - 'a'] + 1 == s1Freq[leftCh - 'a']) matchCount--;
        }

        return matchCount == 26;
    }
}; 