class Solution {
public:
    int maxScore(string s) {
        int n = s.size(), zeroes = 0, ones = 0, best = INT_MIN;

        for (int i = 0; i < n - 1; i++) {
            s[i] == '0' ? zeroes++ : ones++;
            best = max(best, zeroes - ones);
        }
        ones += s[n - 1] == '1';

        return best + ones;
    }
};