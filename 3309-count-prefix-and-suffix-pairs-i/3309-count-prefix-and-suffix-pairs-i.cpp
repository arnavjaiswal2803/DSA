class Solution {
    bool isPrefix(string& str1, string& str2) {
        int n = str1.size(), m = str2.size();
        if (n > m) return false;
        for (int i = 0, j = 0; i < n; i++, j++) if (str1[i]!=str2[j]) return false;
        return true;
    }

    bool isSuffix(string& str1, string& str2) {
        int n = str1.size(), m = str2.size();
        if (n > m) return false;
        for (int i = n - 1, j =  m - 1; i >= 0; i--, j--) 
            if (str1[i]!=str2[j]) return false;
        return true;
    }

    bool isPrefixAndSuffix(string& str1, string& str2) {
        return isPrefix(str1, str2) && isSuffix(str1, str2);
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