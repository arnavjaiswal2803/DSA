class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size(), minCounter = 0, maxCounter = 0;
        if (n & 1) return false;

        for (int i = 0; i < n; i++) {
            if (locked[i] == '1') {
                if (s[i] == '(') {
                    maxCounter++;
                    minCounter++;
                } else {
                    maxCounter--;
                    minCounter--;
                }
            } else {
                maxCounter++;
                minCounter--;
            }

            if (maxCounter < 0) return false;
            if (minCounter < 0) minCounter = 0;
        }

        return minCounter == 0;
    }
};