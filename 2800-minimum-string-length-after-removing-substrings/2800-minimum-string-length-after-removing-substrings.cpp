class Solution {
    bool canFormPattern(char first, char second) {
        return ((first == 'A' && second == 'B') || (first == 'C' && second == 'D'));
    }
public:
    int minLength(string s) {
        int n = s.length();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && i < n && canFormPattern(st.top(), s[i])) {
                st.pop();
                i++;
            }
            if (i < n) st.push(s[i]);
        }
        return st.size();
    }
};