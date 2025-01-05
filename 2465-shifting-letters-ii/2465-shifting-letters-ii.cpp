class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> prefixShifts(n + 1, 0);

        for (vector<int>& shift : shifts) {
            int start = shift[0], end = shift[1] + 1;
            if (shift[2] == 1) {
                prefixShifts[start] += 1;
                prefixShifts[end] -= 1;
            } else {
                prefixShifts[start] -= 1;
                prefixShifts[end] += 1;
            }
        }

        string ans;
        for (int i = 0; i < n; i++) { 
            if (i > 0) prefixShifts[i] += prefixShifts[i - 1];
            prefixShifts[i] = (((prefixShifts[i] % 26) + 26) % 26);
            ans += 'a' + ((s[i] - 'a' + prefixShifts[i]) % 26);
        }

        return ans;
    }
};