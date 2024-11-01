class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (i < 2 || !(s[i] == s[i - 1] && s[i - 1] == s[i - 2])) ans += s[i];
        }
        return ans;
    }
};