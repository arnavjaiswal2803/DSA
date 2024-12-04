class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.size(), m = spaces.size(), j = 0;
        string spacedString = "";
        for (int i = 0; i < n; i++) {
            if (j < m && i == spaces[j]) {
                spacedString += ' ';
                j++;
            }
            spacedString += s[i];
        }
        return spacedString;
    }
};