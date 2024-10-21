class Solution {
    void split(string &s, int n, int idx, unordered_set<string> &hash, int &maxSize) {
        if (idx == n) {
            maxSize = max(maxSize, (int)hash.size());
            return;
        }

        for (int i = 1; idx + i <= n; i++) {
            string substring = s.substr(idx, i);
            if (hash.find(substring) == hash.end()) {
                hash.insert(substring);
                split(s, n, idx + i, hash, maxSize);
                hash.erase(substring);
            }
        }
    }
public:
    int maxUniqueSplit(string s) {
        int n = s.length(), maxSize = 0;
        unordered_set<string> hash;
        split(s, n, 0, hash, maxSize);
        return maxSize;
    }
};