class Solution {
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    bool doesStartsAndEndsWithVowel(string& word) {
        return isVowel(word[0]) && isVowel(word[word.size() - 1]);
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size(), m = queries.size();
        vector<int> prefixSum(n, 0), ans(m);

        for (int i = 0; i < n; i++) {
            if (doesStartsAndEndsWithVowel(words[i])) prefixSum[i] = 1;
            if (i > 0) prefixSum[i] += prefixSum[i - 1];
        }

        for (int i = 0; i < m; i++) {
            int l = queries[i][0], r = queries[i][1];
            ans[i] = prefixSum[r];
            if (l > 0) ans[i] -= prefixSum[l - 1];
        }

        return ans;
    }
};