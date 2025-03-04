class Solution {
public:
    string longestPalindrome(string s) {
        int startIdx = 0, maxLength = 1;
        
        for (int i = 1; i < s.length(); i++) {
            int low = i - 1, high = i;
            while  (low >= 0 && high < s.length() && s[low] == s[high]) {
                if (high - low + 1 > maxLength) {
                    startIdx = low;
                    maxLength = high - low + 1;
                }
                low--; high++;
            }
            
            low = i - 1, high = i + 1;
            while (low >= 0 && high < s.length() && s[low] == s[high]) {
                if (high - low + 1 > maxLength) {
                    startIdx = low;
                    maxLength = high - low + 1;
                }
                low--; high++;
            }
        }
        
        return s.substr(startIdx, maxLength);
    }
};