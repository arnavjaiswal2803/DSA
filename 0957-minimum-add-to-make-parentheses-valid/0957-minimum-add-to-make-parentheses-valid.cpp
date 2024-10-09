class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size(), open = 0, unbalanced = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') open++;
            else if (open > 0) open--;
            else unbalanced++;
        }
        unbalanced += open;
        return unbalanced;
    }
};