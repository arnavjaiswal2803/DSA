class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> isAllowed;
        for (auto &ch : allowed) isAllowed.insert(ch);

        int count = 0;
        for (auto &word : words) {
            bool isConsistent = true;
            for (auto &ch : word) {
                if (isAllowed.find(ch) == isAllowed.end()) {
                    isConsistent = false;
                    break;
                }
            }
            if (isConsistent) count++;
        }

        return count;
    }
};