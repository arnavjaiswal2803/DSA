class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256, -1);
        int start = 0, end = 0, maxLen = 0, n = s.length();
        while (end < n) {
            if (hash[s[end]] >= start) start = hash[s[end]] + 1;
            hash[s[end]] = end;
            maxLen = max(maxLen, end - start + 1);
            end++;
        }
        return maxLen;
    }
};