class Solution {
    bool isPrefixAndSuffix(string& str1, string& str2) {
        int n = str1.size(), m = str2.size();
        if (n > m) return false;

        int prefixI = 0, prefixJ = 0, suffixI = n - 1, suffixJ = m - 1;
        while (prefixI < n && suffixI >= 0) {
            if (str1[prefixI++] != str2[prefixJ++]) return false;
            if (str1[suffixI--] != str2[suffixJ--]) return false;
        }
        
        return true;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size(), count = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) 
                if (isPrefixAndSuffix(words[j], words[i])) count++;
        }
        return count;
    }
};