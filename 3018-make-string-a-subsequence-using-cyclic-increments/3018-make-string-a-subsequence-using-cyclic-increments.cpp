class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        if (m > n) return false;

        int i = 0, j = 0;
        while (i < n && j < m) {
            char currCh = str1[i];
            char nextCh = str1[i] != 'z' ? str1[i] + 1 : 'a';
            
            if (str2[j] == currCh || str2[j] == nextCh) j++;
            i++;
        }

        return j == m;
    }
};