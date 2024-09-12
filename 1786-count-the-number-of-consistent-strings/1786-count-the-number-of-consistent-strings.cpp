class Solution {
    void setBit(int &num, int i) {
        num |= (1 << i);
    }

    int getBit(int num, int i) {
        return (num & (1 << i)) > 0;
    }
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int allowedChars = 0, count = words.size();
        for (auto &ch : allowed) setBit(allowedChars, ch - 'a');
        for (auto &word : words) {
            for (auto &ch : word) {
                if (getBit(allowedChars, ch - 'a') == 0) {
                    count--;
                    break;
                }
            }
        }
        return count;
    }
};