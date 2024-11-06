class Solution {
public:
    int minChanges(string s) {
        int minChanges = 0, n = s.length();
        for (int i = 0; i < n; i += 2) if (s[i] != s[i + 1]) minChanges++;
        return minChanges;
    }
};