class Solution {
    int lcs(string& s1, string& s2) {
        int n = s1.size(), m = s2.size();
        vector<int> prev(m);

        for (int idx1 = 0; idx1 < n; ++idx1) {
            vector<int> curr(m);
            for (int idx2 = 0; idx2 < m; ++idx2) {
                if (idx1 == 0 && idx2 == 0) curr[idx2] = s1[idx1] == s2[idx2];
                else {
                    int equal = 0, unequal1 = 0, unequal2 = 0;
                    if (s1[idx1] == s2[idx2]) {
                        equal = 1;
                        if (idx1 > 0 && idx2 > 0) equal += prev[idx2 - 1];
                    } else {
                        if (idx1 > 0) unequal1 = prev[idx2];
                        if (idx2 > 0) unequal2 = curr[idx2 - 1];
                    }

                    curr[idx2] = max({equal, unequal1, unequal2});
                }
            }
            prev = curr;
        }

        return prev[m - 1];
    }
public:
    int minInsertions(string s) {
        string reverseS = s;
        reverse(reverseS.begin(), reverseS.end());
        return s.size() - lcs(s, reverseS);
    }
};