class Solution {
public:
    int minChanges(string s) {
        int zeroCount = 0, oneCount = 0, changes = 0, n = s.length();
        for (int i = 0; i < n; i++) {
            s[i] == '0' ? zeroCount++ : oneCount++;

            if (i & 1) {
                if (zeroCount & 1) changes++;
                zeroCount = 0;
                oneCount = 0;
            }
        }
        return changes;
    }
};