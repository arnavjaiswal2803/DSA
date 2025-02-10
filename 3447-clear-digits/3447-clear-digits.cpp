class Solution {
    bool isDigit(char ch) { 
        return ch >= '0' && ch <= '9'; 
    }
public:
    string clearDigits(string s) {
        int n = s.size(), skip = 0;
        string ans = "";

        for (int i = n - 1; i >= 0; i--) {
            if (isDigit(s[i])) skip++; 
            else if (skip == 0) ans += s[i];
            else skip--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};