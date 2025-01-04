class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size(), ans = 0;
        vector<int> firstIdx(26, -1), lastIdx(26, -1);

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            
            if (firstIdx[ch - 'a'] == -1) firstIdx[ch - 'a'] = i;
            lastIdx[ch - 'a'] = i;
        }

        for (int i = 0; i < 26; i++) {
            if (firstIdx[i] != lastIdx[i]) {
                unordered_set<char> uniqueChars;
                for (int j = firstIdx[i] + 1; j < lastIdx[i]; j++) 
                    uniqueChars.insert(s[j]);
                ans += uniqueChars.size();
            } 
        }

        return ans;
    }
};