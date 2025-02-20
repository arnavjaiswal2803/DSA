class Solution {
    bool getNum(int idx, int n, string& pattern, string& curr, string& ans, 
        bitset<10>& isUsed) {
            if (idx == n + 1) {
                ans = curr;
                return true;
            }

            for (int i = 1; i <= 9; i++) {
                if (idx == 0) {
                    isUsed[i] = true;
                    curr += to_string(i);
                    if (getNum(idx + 1, n, pattern, curr, ans, isUsed)) 
                        return true;
                    curr.pop_back();
                    isUsed[i] = false;
                } else {
                    if (pattern[idx - 1] == 'I') {
                        if (!isUsed[i] && i > (curr[idx - 1] - '0')) {
                            isUsed[i] = true;
                            curr += to_string(i);
                            if (getNum(idx + 1, n, pattern, curr, ans, isUsed)) 
                                return true;
                            curr.pop_back();
                            isUsed[i] = false;
                        } 
                    } else {
                        if (!isUsed[i] && i < (curr[idx - 1] - '0')) {
                            isUsed[i] = true;
                            curr += to_string(i);
                            if (getNum(idx + 1, n, pattern, curr, ans, isUsed))
                                return true;
                            curr.pop_back();
                            isUsed[i] = false;
                        }
                    }
                }
            }
            return false;
    }
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string curr = "", ans = "";
        bitset<10> isUsed;
        getNum(0, n, pattern, curr, ans, isUsed);
        return ans;
    }
};