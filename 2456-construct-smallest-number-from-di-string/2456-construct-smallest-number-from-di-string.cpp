class Solution {
    bool getNum(int idx, int n, string& pattern, string curr, string& ans,
                bitset<10>& isUsed) {
        if (idx == n + 1) {
            ans = curr;
            return true;
        }

        for (int i = 1; i <= 9; i++) {
            if (!isUsed[i] &&
                (idx == 0 ||
                 (pattern[idx - 1] == 'I' && i > curr[idx - 1] - '0') ||
                 (pattern[idx - 1] == 'D' && i < curr[idx - 1] - '0'))) {

                isUsed[i] = true;
                if (getNum(idx + 1, n, pattern, curr + to_string(i), ans, isUsed))
                    return true;
                isUsed[i] = false;
            }
        }
        return false;
    }

public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string ans = "";
        bitset<10> isUsed;
        getNum(0, n, pattern, "", ans, isUsed);
        return ans;
    }
};