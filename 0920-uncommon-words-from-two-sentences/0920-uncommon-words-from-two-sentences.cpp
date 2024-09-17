class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        vector<string> ans;
        map<string, int> freq;

        string word = "";
        for (int i = 0; i < n; i++) {
            if (s1[i] != ' ') word += s1[i];
            else {
                freq[word]++;
                word = "";
            }
        }
        freq[word]++;
        word = "";

        for (int i = 0; i < m; i++) {
            if (s2[i] != ' ') word += s2[i];
            else {
                freq[word]++;
                word = "";
            }
        }
        freq[word]++;
        word = "";

        for (auto &it : freq) {
            if (it.second == 1) ans.push_back(it.first);
        }

        return ans;
    }
};