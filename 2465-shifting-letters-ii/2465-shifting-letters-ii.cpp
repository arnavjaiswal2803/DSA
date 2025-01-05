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

        for (int i = 1; i <= n; i++) prefixShifts[i] += prefixShifts[i - 1];

        for (int i = 0; i < n; i++) 
            prefixShifts[i] = (((prefixShifts[i] % 26) + 26) % 26);

        string ans;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            while (prefixShifts[i]--) {
                ch++;
                if (ch > 'z') ch = 'a';
            }
            ans += ch;
        }

        return ans;
    }
};